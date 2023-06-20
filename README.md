Below is the pseudo code:

main function:
if argc == 2:
	read file in argv[1]
	if file cannot be read:
		exit with EXIT_FAILURE
	else:
		declare buffer = NULL
		declare buffer_size = 0
		declare line_number = 1

		while (getline()):
			declare opcode = strtok(buffer, " ")
			declare arg = atoi(strtok(NULL, " "))
	
			check if !(opcode is push or pall or pint or pop or swap) or arg is not number:
				free_stack()
				print line number {line_number} failed
				exit with EXIT_FAILURE
			else:
				implement commands
				line_number ++
				
else:
	print an error
	exit with EXIT_FAILURE

typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

push function (value):
	declare and allocate node
	if new_node not created:
		exit with EXIT_FAILURE
	else:
		node->n = value;
		
		if top exists:
			top->prev = node

		node->next = top;
		npde->prev = null;
		top = node;

		return node;

pall:
	declare temp_head = top;
	for (; temp_head; temp_head = temp_head->next)
		print temp_head->n \n

pint:
	if (top exist)
		print top->n
	else:
		print {line_number} can't pint, stack empty
		exit with EXIT_FAILURE

pop
	declare temp_head;
	if (top exists)
		temp_head = top;
		top = top->next;
		top->prev = NULL;
		free(temp_head)

swap:
	if (head && head->next)
		declare temp_n
		temp_n = head->n
		head-> = head->next->n
		head->next->n = temp_n
	else:
		print stack too shor
		exit with EXIT_FAILURE

add:
	if (head && head->next)
		head->next->n += head->n
		pop()
	else:
		print stack too shor
		exit with EXIT_FAILURE
nop:
	return
	