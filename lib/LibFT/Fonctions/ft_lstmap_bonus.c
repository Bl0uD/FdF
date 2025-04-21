/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 23:19:12 by jdupuis           #+#    #+#             */
/*   Updated: 2025/04/16 15:55:12 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

t_list	*create_new_node(void *(*f)(void *), t_list *lst, void (*del)(void *))
{
	void	*temp;
	t_list	*new_node;

	temp = f(lst->content);
	if (!temp)
		return (NULL);
	new_node = ft_lstnew(temp);
	if (!new_node)
	{
		del(temp);
		return (NULL);
	}
	return (new_node);
}

t_list	*apply_function(t_list *lst, void *(*f)(void *),
			void (*del)(void *), t_list **head)
{
	t_list	*n_lst;
	t_list	*new_node;

	n_lst = *head;
	while (lst && lst->next)
	{
		new_node = create_new_node(f, lst->next, del);
		if (!new_node)
		{
			ft_lstclear(head, del);
			return (NULL);
		}
		n_lst->next = new_node;
		n_lst = n_lst->next;
		lst = lst->next;
	}
	return (*head);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;

	if (!lst || !f || !del)
		return (NULL);
	head = create_new_node(f, lst, del);
	if (!head)
		return (NULL);
	if (!apply_function(lst, f, del, &head))
		return (NULL);
	return (head);
}
