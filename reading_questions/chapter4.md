## Chapter 4


### Files and file systems

1) What abstractions do file systems provide?  Give an example of something that is logically true about file systems but not true of their implementations.

File systems provide the abstraction that files are streams on top of an underlying mechanism which is block-based.

The file system abstraction lets you open whole files at once, while the implementation often (if the file doesn't fit in a single block) requires you to touch multiple blocks in sequence.

2) What information do you imagine is stored in an `OpenFileTableEntry`?

I'd imagine that an `OpenFileTableEntry` keeps track of the contents which have been read so far and the current reading position.

3) What are some of the ways operating systems deal with the relatively slow performance of persistent storage?

Operating systems should load whole blocks instead of parts of blocks because the overhead required to load a whole block compared to a part of a block is negligible -- might as well get as much information as possible from persistent memory for approximately the same cost. Additionally, operating systems can prefetch blocks -- predict that processes will read a block and start loading it before it is requested. They can also buffer blocks, modifying them in memory and only writing them to persistent storage after all (or at least many) modifications have occurred. They can also cache files -- keep copies of blocks they've used recently in memory in case they need to use them again.

4) Suppose your program writes a file and prints a message indicating that it is done writing. Then a power cut crashes your computer.  After you restore power and reboot the computer, you find that the file you wrote is not there.  What happened?

Maybe the message indicating that the program was done writing the file indicated that the file was done being written to memory, but the memory was being buffered before being written to storage and the write to storage hadn't happened (or at least hadn't completed) yet.

5) Can you think of one advantage of a File Allocation Table over a UNIX inode?  Or an advantage of a inode over a FAT?

It's easier to move files if you're using inodes -- moving the pointer to an inode moves the file, while with FAT you have to move both the metadata and the block itself.

6) What is overhead?  What is fragmentation?

Overhead is the amount of space taken up by the data structures used by the block allocation system. Fragmentation is the unused space which occurs when the block allocation system leaves some blocks unused or partially used.

7) Why is the "everything is a file" principle a good idea?  Why might it be a bad idea?

The "everything is a file" principle is a good idea because it makes programs more versatile -- programs intended to work with files can also be used to work with data coming from pipes and other sources.

It might be a bad idea because it requires engineers to fit every implementation into the same abstraction -- anything you build which works with file data has to work with streams.

If you would like to learn more about file systems, a good next step is to learn about journaling file systems.
Start with [this Wikipedia article](https://en.wikipedia.org/wiki/Journaling_file_system), then
[Anatomy of Linux Journaling File Systems](http://www.ibm.com/developerworks/library/l-journaling-filesystems/index.html).
Also consider reading [this USENIX paper](https://www.usenix.org/legacy/event/usenix05/tech/general/full_papers/prabhakaran/prabhakaran.pdf).
