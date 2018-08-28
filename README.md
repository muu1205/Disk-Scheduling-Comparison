# Disk-Scheduling-Comparison

Disk Scheduling is the method in which the operating systems decide in which order I/O operations are executed. Thus it is sometimes
also called Input/output (I/O) Scheduling. In operating systems, seek time is very important. Since all device requests are linked in
queues, the seek time is increased causing the system to slow down. Disk Scheduling Algorithms are used to reduce the total seek time
of any request.
The main purpose of the I/O Schedulers is dependent on the purpose of the operating system:
1. Decrease the time wasted by hard-disk seeks
2. To prioritize certain processes’ I/O request
3. To give a share of the bandwidth to each running process
4. To guarantee that each process request will be handled before a particular deadline.
In this project we will demonstrate various Disk Scheduling algorithms like
i. FCFS
ii. SSTF
iii. SCAN
iv. C-SCAN
v. LOOK
vi. C-LOOK
There are many Disk Scheduling Algorithms but before discussing them let’s have a quick look at some of the important terms:
 Seek Time: Seek time is the time taken to locate the disk arm to a specified track where the data is to be read or write.
              So the disk scheduling algorithm that gives minimum average seek time is better. 
 Rotational Latency: Rotational Latency is the time taken by the desired sector of disk to rotate into a position so that it can 
              access the read/write heads. So the disk scheduling algorithm that gives minimum rotational latency is better.
 Transfer Time: Transfer time is the time to transfer the data. It depends on the rotating speed of the disk and number of bytes
                  to be transferred. 
 Disk Access Time: Disk Access Time is:
                    Disk Access Time = Seek Time + Rotational Latency + Transfer Time
 Disk Response Time: Response Time is the average of time spent by a request waiting to perform its I/O operation. 
                       Average Response time is the response time of the all requests. 
                       Variance Response Time is measure of how individual request are serviced with respect to average response time. 
                       So the disk scheduling algorithm that gives minimum variance response time is better.
                       
We will also try to implement some of the new disk scheduling algorithm proposed by scientist all around the world like:
i.) SSEDO (Shortest Seek Time and Earliest Deadline by Ordering)
ii.) SSEDV (Shortest Seek Time and Earliest Deadline by Value)
Finally we will compare all the different algorithms and come up with the best algorithm for different purposes.
