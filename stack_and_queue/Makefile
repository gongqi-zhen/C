all: stack queue queue-nobuf

stack:
	cc -o stack stack.c

queue:
	cc -o queue queue.c

queue-nobuf:
	cc -o no_ringbuf_queue no_ringbuf_queue.c

clean:
	rm stack queue no_ringbuf_queue