// proc.c, 159
// processes are here

<<<<<<< HEAD
#include "sys_calls.h"
#include "spede.h"   // for IO_DELAY() needed here below
#include "externs.h" // for cur_pid needed here below
#include "proc.h"
=======
#include "spede.h"   // for IO_DELAY() needed here below
#include "externs.h" // for cur_pid needed here below
#include "proc.h"
#include "sys_calls.h"
#include "q_mgmt.h"
>>>>>>> b8a9e70220cc217dedb00b209013c8d21b381054

void IdleProc()
{
	int i;
	while(1)
	{
		cons_printf("0 ");
		for(i=0;i<1666000;i++) IO_DELAY(); // delay for about 1 sec
	}
}


<<<<<<< HEAD
// void SimpleProc(){
//     int pid;
//     pid = GetPid();
//     while(1)
//     {
//         int sleep_secs = (pid %5)+1; 
//         cons_printf("%d ", pid);
//         Sleep(sleep_secs);
//     }
// }

void Init() // handles key events, move the handling code out of Kernel()
{
	int i;
	product_num = 0; // set product_num to zero
	common_sid = SemInit(1); //get "common_sid" thru SemInit() call
=======
void Init() // handles key events, move the handling code out of Kernel()
{
	int i;
	msg_t initmsg;
	product_num = 0; // set product_num to zero
	common_sid = SemInit(1); //get "common_sid" thru SemInit() call
	for (i = 0; i < BUFF_SIZE; i++) {
		MsgSnd(0, &initmsg);
	}
>>>>>>> b8a9e70220cc217dedb00b209013c8d21b381054
	while (1){
		cons_printf("%d ", GetPid());
		for(i=0;i<1666000;i++) IO_DELAY(); // delay for about 1 sec
		if (cons_kbhit()){
			char key = cons_getchar(); // get the pressed key
			int child_pid;
			switch(key) // see if it's one of the following for service
			{
				case 'p':
					child_pid = Spawn(Producer);
<<<<<<< HEAD
					break;
				case 'c':
					child_pid = Spawn(Consumer);
					break;
				//case 's': ShowStatusISR(); break;
				case 'b': breakpoint(); break; // this stops when run in GDB mode
				case 'q': exit(0);
			} // switch(key)
		} // if(cons_kbhit()) 
=======
					initmsg.numbers[0] = 0;
					initmsg.numbers[1] = 1;
					initmsg.numbers[2] = (child_pid % 4) + 1;
					MsgSnd(child_pid, &initmsg);
					break;
				case 'c':
					child_pid = Spawn(Consumer);
					initmsg.numbers[0] = 0;
					initmsg.numbers[1] = 1;
					initmsg.numbers[2] = (child_pid % 4) + 1;
					MsgSnd(child_pid, &initmsg);
					break;
					//case 's': ShowStatusISR(); break;
				case 'b': breakpoint(); break; // this stops when run in GDB mode
				case 'q': exit(0);
			} // switch(key)
		} // if(cons_kbhit())
>>>>>>> b8a9e70220cc217dedb00b209013c8d21b381054

	}
}

void Producer()
{
<<<<<<< HEAD
   int i, pid = GetPid();
   msg_t msg;	// this is local, repeatedly used in loop
   char *fruits[] = 
		{"apple\0","banana\0","cherry\0","durian\0","eggplant\0","fig\0","guava\0"};	
   
   sleep_secs = (pid%4)+1;  // 1 to 4 secsd

   while(1)
   {
      MsgRcv(producer_mid, &msg); // get a msg (product container)
      memcpy(msg.bytes,fruits[(pid % 7)],sizeof(msg.bytes));
      cons_printf("\nProducer %d is producing: %s\n", pid, msg.bytes);
      
      for(i=0; i<1666000; i++) IO_DELAY(); // make CPU busy for .5 sec
      		   
      MsgSnd(consumer_mid, &msg); // out of critical section

      Sleep(sleep_secs);
   }
=======
	int i, pid = GetPid();
	int consumer_id, producer_id, sleep_secs;
	msg_t msg;	// this is local, repeatedly used in loop
	char *fruits[] = {"apple\0","banana\0","cherry\0","durian\0","eggplant\0","fig\0","guava\0"};
	MsgRcv(pid, &msg);
	producer_id = msg.numbers[0];
	consumer_id = msg.numbers[1];
	sleep_secs = msg.numbers[2];

	while(1)
	{
		MsgRcv(producer_id, &msg); // get a msg (product container)
		MyStrCpy(msg.bytes,fruits[(pid % 7)]);
		cons_printf("\nProducer %d is producing: %s\n", pid, msg.bytes);

		for(i=0; i<1666000; i++) IO_DELAY(); // make CPU busy for .5 sec

		MsgSnd(consumer_id, &msg); // out of critical section

		Sleep(sleep_secs);
	}
>>>>>>> b8a9e70220cc217dedb00b209013c8d21b381054
}

void Consumer()
{
<<<<<<< HEAD
   int i, pid = GetPid();
   msg_t msg;     // this is local, repeatedly used in loop
   
   sleep_secs = (pid%4)+1;  // 1 to 4 secsd

   while(1)
   {
      	Sleep(sleep_secs);

      	MsgRcv(consumer_mid, &msg); // get a message, a product

      	cons_printf("Consumer %d is consumng: %s\n", pid, msg.bytes);
	for(i=0; i<1666000; i++) IO_DELAY(); // make CPU busy for .5 sec	
        
	memcpy(msg.bytes,"EMPTY\0",sizeof(msg.bytes));
	MsgSnd(producer_mid, &msg);
   }
} loop
=======
	int i, pid = GetPid();
	msg_t msg;     // this is local, repeatedly used in loop
	int consumer_id, producer_id, sleep_secs;
	MsgRcv(pid, &msg);
	producer_id = msg.numbers[0];
	consumer_id = msg.numbers[1];
	sleep_secs = msg.numbers[2];

	while(1)
	{
		Sleep(sleep_secs);

		MsgRcv(consumer_id, &msg); // get a message, a product

		cons_printf("Consumer %d is consuming: %s\n", pid, msg.bytes);
		for(i=0; i<1666000; i++) IO_DELAY(); // make CPU busy for .5 sec

		MyStrCpy(msg.bytes,"EMPTY\0");
		MsgSnd(producer_id, &msg);
	}
>>>>>>> b8a9e70220cc217dedb00b209013c8d21b381054
} // Consumer()


