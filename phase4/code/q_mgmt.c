// q_mgmt.c, 159

#include "spede.h"
#include "types.h"
#include "externs.h"
<<<<<<< HEAD

int EmptyQ(q_t *p)
{
   return (p->count == 0);
=======
#include "q_mgmt.h"

int EmptyQ(q_t *p)
{
	return (p->count == 0);
>>>>>>> b8a9e70220cc217dedb00b209013c8d21b381054
}

int FullQ(q_t *p)
{
	return (p->count == Q_SIZE);
}

void InitQ(q_t *p)
{
	p->count = 0;
	p->head = 0;
	p->tail = 0;
}

int DeQ(q_t *p) // return -1 if q is empty
{
	int pid;

	if (EmptyQ(p)) {
		cons_printf("Queue is empty, can't dequeue!\n");
		return -1;
	}
<<<<<<< HEAD
	
	pid = p->q[p->head];
	
=======

	pid = p->q[p->head];

>>>>>>> b8a9e70220cc217dedb00b209013c8d21b381054
	p->head += 1;

	if (p->head >= Q_SIZE) {
		p->head = 0;
	}

	p->count -= 1;

	return pid;
}

void EnQ(int element, q_t *p)
{
	if (FullQ(p)) {
		cons_printf("Queue is full, can't enqueue!\n");
		return;
	}
	p->q[p->tail] = element;

	p->tail += 1;

	if (p->tail >= Q_SIZE) {
		p->tail = 0;
	}

	p->count += 1;
}

int MsgQFull(msg_q_t *p)
{
<<<<<<< HEAD
	return(p->count == 20);
=======
	return(p->count == NUM_MSG);
>>>>>>> b8a9e70220cc217dedb00b209013c8d21b381054
}

int MsgQEmpty(msg_q_t *p)
{
	return(p->count == 0);
}

void EnQMsg(msg_t *p, msg_q_t *q)
{
<<<<<<< HEAD
  int t_p = q->tail;		
  	memcpy(&(q->msgs[t_p]),p,sizeof(msg_t));
	if(q->tail == (Q_SIZE-1))
=======
	int t_p = q->tail;
	MyMemCpy((char*)&(q->msgs[t_p]),(char*)p,sizeof(msg_t));
	if(q->tail >= Q_SIZE)
>>>>>>> b8a9e70220cc217dedb00b209013c8d21b381054
		q->tail = 0;
	else
		q->tail++;
	q->count++;
}

msg_t *DeQMsg(msg_q_t *p)
{
<<<<<<< HEAD
  msg_t *msg;
  int h_p = p -> head;
  
	
	if(p->count > 0)
	{	
		msg = (msg_t*)&(p->msgs[h_p]);
		if(p->head == (Q_SIZE-1))
=======
	msg_t *msg;
	int h_p = p -> head;


	if(p->count > 0)
	{
		msg = (msg_t*)&(p->msgs[h_p]);
		if(p->head >= Q_SIZE)
>>>>>>> b8a9e70220cc217dedb00b209013c8d21b381054
			p->head = 0;
		else
			p->head++;
		p->count--;
	}
	else
		msg = 0;
	return msg;
}
<<<<<<< HEAD
=======

void MyBZero(char *p, int size)
{
   while( size-- ) *p++ = 0; // they'll be all nulls
}

void MyMemCpy(char *dest, char *src, int size)
{
   while(size--) *dest++ = *src++;
}


void MyStrCpy(char *dest, char *src)
{
	while(*src != '\0') *dest++ = *src++;
	*dest = '\0';
}
>>>>>>> b8a9e70220cc217dedb00b209013c8d21b381054
