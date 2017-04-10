/*
Word histogrammer
For https://github.com/AllenDowney/ExercisesInC/blob/master/exercises/ex08/ex08.md
Author: Sarah Walters
*/

#include <stdio.h>
#include <stdlib.h>
#include <glib.h>
#include <string.h>

/*
Defines a HistogramEntry structure
gchar *word is a string
count is a number of occurrences
*/
typedef struct histogram_entry {
    gchar *word;
    int count;
} HistogramEntry;

/*
Creates a HistogramEntry on the heap
Returns a pointer to the newly created entry in allocated memory
*/
HistogramEntry* make_histogram_entry(gchar* word, int count) {
    HistogramEntry *h = malloc(sizeof(HistogramEntry));
    h->word = word;
    h->count = count;
    return h;
}

void destroy_histogram_entry(gpointer data) {
    HistogramEntry *h = (HistogramEntry*) data;
    free(h);
}

/*
Prints a histogram entry in "word, count" format
*/
void print_histogram_entry(HistogramEntry *h) {
    printf("%s, %i\n", h->word, h->count);
}

/*
GFunc wrapper for print_histogram_entry
*/
void gprint_histogram_entry(gpointer data, gpointer user_data) {
    HistogramEntry *h = (HistogramEntry*) data;
    print_histogram_entry(h);
}

/*
Comparator which sorts histogram entries by increasing count
*/
int increasing_count_histogram_entry(gconstpointer a, gconstpointer b) {
    HistogramEntry *ha = (HistogramEntry*) a;
    HistogramEntry *hb = (HistogramEntry*) b;
    return ha->count - hb->count;
}

/*
Appends an element from a GHashTable onto a GSList
key and value are gpointers to the components of an entry in a GHashTable
key can be cast to a gchar*, value can be cast to an int*
head_ptr is a gpointer to the head of the GSList and can be cast to GSList**
*/
void hash_table_to_slist(gpointer key, gpointer value, gpointer head_ptr) {
    gchar *word = (gchar*) key;
    int count = *(int*) value;
    HistogramEntry *h = make_histogram_entry(word, count);
    GSList *list = *(GSList**) head_ptr;
    list = g_slist_insert_sorted(list, h, increasing_count_histogram_entry);
    *(GSList**) head_ptr = list;
}

void value_destroy(gpointer value) {
    free(value);
}

/*
Prints a histogram of the words in a text file
filename specifies the text file to histogram
returns 0 if success, 1 if error
*/
int print_histogram(char* filename) {
    // Read from file
    gsize length;
    gchar *content;
    GError *error = NULL;
    g_file_get_contents(filename, &content, &length, &error);
    if (error != NULL) {
        fprintf(stderr, "Unable to read file: %s\n", error->message);
        g_error_free(error);
        return 1;
    }

    // Split string into words
    gchar *delimiters = " \n\t\v\f\r\"“”,.:;*!?()"; // all whitespace characters & common punctuation
    gint max_tokens = 0; // split string completely
    gchar **split_content = g_strsplit_set(content, delimiters, max_tokens);

    // Histogram the words
    int i = 0;
    gpointer lookup;
    GHashTable *histogram = g_hash_table_new_full(g_str_hash, g_str_equal, NULL, value_destroy);
    while (split_content[i] != NULL) {
        if (strlen(split_content[i]) > 0) {
            lookup = g_hash_table_lookup(histogram, split_content[i]);

            if (lookup == NULL) {
                // first instance of key
                int *value = malloc(sizeof(int));
                *value = 1;
                g_hash_table_insert(histogram, split_content[i], value);
            } else {
                // key exists already
                (*((int*) lookup))++;
            }
        }

        i++;
    }

    // Print the histogram in sorted order
    GSList *list = NULL;
    g_hash_table_foreach(histogram, hash_table_to_slist, &list);
    g_slist_foreach(list, gprint_histogram_entry, NULL);

    // Free memory
    g_free(content);
    g_strfreev(split_content);
    g_hash_table_destroy(histogram);
    g_slist_free_full(list, destroy_histogram_entry);

    return 0;
}

int main(int argc, char** argv) {
    return print_histogram("totc.txt");
}
