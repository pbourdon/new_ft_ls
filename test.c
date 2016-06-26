#include "libls.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
void	ft_putstr(char *str)
{
	int		index;

	index = 0;
	while (str[index] != '\0')
	{
		ft_putchar(str[index]);
		index++;
	}
}

Dlist *dlist_append(Dlist *p_list, int data)
{
	    if (p_list != NULL) /* On vérifie si notre liste a été allouée */
			    {
					        struct node *p_new = malloc(sizeof *p_new); /* Création d'un nouveau node */
							        if (p_new != NULL) /* On vérifie si le malloc n'a pas échoué */
										        {
													            p_new->data = data; /* On 'enregistre' notre donnée */
																            p_new->p_next = NULL; /* On fait pointer p_next vers NULL */
																			            if (p_list->p_tail == NULL) /* Cas où notre liste est vide (pointeur vers fin de liste à  NULL) */
																							            {
																											                p_new->p_prev = NULL; /* On fait pointer p_prev vers NULL */
																															                p_list->p_head = p_new; /* On fait pointer la tête de liste vers le nouvel élément */
																																			                p_list->p_tail = p_new; /* On fait pointer la fin de liste vers le nouvel élément */
																																							            }
																						            else /* Cas où des éléments sont déjà présents dans notre liste */
																										            {
																														                p_list->p_tail->p_next = p_new; /* On relie le dernier élément de la liste vers notre nouvel élément (début du chaînage) */
																																		                p_new->p_prev = p_list->p_tail; /* On fait pointer p_prev vers le dernier élément de la liste */
																																						                p_list->p_tail = p_new; /* On fait pointer la fin de liste vers notre nouvel élément (fin du chaînage: 3 étapes) */
																																										            }
																									            p_list->length++; /* Incrémentation de la taille de la liste */
																												        }
									    }
		    return p_list; /* on retourne notre nouvelle liste */
}

Dlist *dlist_prepend(Dlist *p_list, int data)
{
	    if (p_list != NULL)
			    {
					        struct node *p_new = malloc(sizeof *p_new);
							        if (p_new != NULL)
										        {
													            p_new->data = data;
																            p_new->p_prev = NULL;
																			            if (p_list->p_tail == NULL)
																							            {
																											                p_new->p_next = NULL;
																															                p_list->p_head = p_new;
																																			                p_list->p_tail = p_new;
																																							            }
																						            else
																										            {
																														                p_list->p_head->p_prev = p_new;
																																		                p_new->p_next = p_list->p_head;
																																						                p_list->p_head = p_new;
																																										            }
																									            p_list->length++;
																												       }
									    }
		    return p_list;
}


Dlist *ins_avant (Dlist * liste, int data, int pos){
	int i;
	ft_putstr("here2\n");
	struct node  *nouveau_element, *courant;
	ft_putstr("here3\n");
	nouveau_element = malloc(sizeof(*nouveau_element));
	ft_putstr("here\n");
	if (nouveau_element == NULL)
		return (liste);
//	strcpy (nouveau_element->data, donnee);
	nouveau_element->data = data;
	courant = liste->p_head;
	for (i = 1; i < pos; ++i)
		courant = courant->p_next;
	nouveau_element->p_next = courant;
	nouveau_element->p_prev = courant->p_prev;
	if(courant->p_prev == NULL)
		liste->p_head = nouveau_element;
	else
		courant->p_prev->p_next = nouveau_element;
	courant->p_prev = nouveau_element;
	liste->length++;
	return (liste);
}

Dlist *dlist_new(void)
{
	    Dlist *p_new = malloc(sizeof *p_new);
		    if (p_new != NULL)
			{
						        p_new->length = 0;
								        p_new->p_head = NULL;
										        p_new->p_tail = NULL;
												    }
			    return p_new;
}


void	ft_display_list(Dlist *p_list)
{
	int		compteur;

	compteur = 1;
				ft_putstr("--------------------- NOUVELLE LISTE ---------------\n");
				printf("------------------------ NOUVELLE LISTE --------------\n");
					if (p_list != NULL)
							{
										struct node *p_temp = p_list->p_head;
												while (p_temp != NULL)
															{
																	//		printf("%d", compteur);
																						printf(" %d", p_temp->data);
																//									printf("%s\n", p_temp->path);
																												p_temp = p_temp->p_next;
																															compteur++;
																																	}
													}
					printf("\n-----------------------------FIN DE LA LISTE --------------\n");
						ft_putstr("---------------------- FIN DE LALISTE ---------------\n");
}

int		main(void)
{
	Dlist *list = NULL;
	list = dlist_new();

	list = dlist_prepend(list, 1);
	list = dlist_append(list, 2);
ft_display_list(list);
	list = ins_avant(list, 5, 1);
ft_display_list(list);
		list = ins_avant(list, 6, 2);
ft_display_list(list);
 list = ins_avant(list, 1, 1);


	ft_display_list(list);

}
