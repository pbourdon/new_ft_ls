#include "libls.h"

void	dlist_display(Dlist *p_list)
{
	if (p_list != NULL)
	{
		struct node *p_temp = p_list->p_head;
		while (p_temp != NULL)
		{
			printf("%s -> ", p_temp->name);
			fflush(stdout);
			p_temp = p_temp->p_next;
		}
	}
	printf("NULL\n");
}
