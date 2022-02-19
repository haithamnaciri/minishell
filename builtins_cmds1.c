/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_cmds1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaciri- <hnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 09:31:41 by hnaciri-          #+#    #+#             */
/*   Updated: 2022/02/19 14:37:04 by hnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

unsigned long long	my_atoi (char *s)
{
	unsigned long long	num;
	int					o;
	int					i;

	o = 1;
	num = 0;
	i = 0;
	if (s[i] == '-' || s[i] == '+')
		if (s[i++] == '-')
			o = -1;
	while (s[i] >= '0' && s[i] <= '9')
	{
		num = (num * 10) + (*s - '0');
		s++;
	}
	return (num * o);
}

void	ft_exit(t_mini_data *mini_data)
{
	t_token	*token;
	int		i;
	
	i = -1;
	printf("exit\n");
	if (!mini_data->token_list->next)
		exit (0);
	token = mini_data->token_list->next;
	while (token->tok[++i])
		if (!ft_isnum (token->tok[i]) && (i != 0 && token->tok[i] != '-' && token->tok[i] != '+'))
		{
			printf ("minishell : exit: %s: numeric argument required\n", token->tok);
			exit (255);
		}
	if (my_atoi (token->tok) > __LONG_MAX__)
	{
		printf ("minishell : exit: %s: numeric argument required\n", token->tok);
		exit (255);
	}
	i = 0;
	while (token)
	{
		i++;
		token = token->next;
	}
	token = mini_data->token_list->next;
	if (i > 1)
		printf ("bash : exit: too many arguments\n");
	else
	{
		printf (" | %s | %llu |\n", token->tok, my_atoi (token->tok));
		exit (my_atoi (token->tok) % 256);
	}
}

void	ft_env(void)
{
	int	i;

	i = 0;
	while (g_data.my_env[i])
	{
		printf("%s\n", g_data.my_env[i]);
		i++;
	}
	g_data.errsv = 0;
}

void	ft_pwd(void)
{
	char	*tmp;

	tmp = getcwd(NULL, 0);
	printf("%s\n", tmp);
	free(tmp);
	g_data.errsv = 0;
}

void	ft_unset(t_mini_data *mini_data)
{
	t_token	*head;
	char	**new_env;
	int		i_and_j[2];
	int		tmp;

	i_and_j[0] = -1;
	i_and_j[1] = -1;
	tmp = 0;
	g_data.errsv = 0;
	head = grep_a_type(mini_data->token_list, CMD);
	new_env = alloc_new_env(head, &tmp);
	while (g_data.my_env[++i_and_j[0]])
		if (!ft_check(head, g_data.my_env[i_and_j[0]]))
			new_env[++i_and_j[1]] = ft_strdup(g_data.my_env[i_and_j[0]]);
	new_env[++i_and_j[1]] = NULL;
	ft_free (g_data.my_env);
	g_data.my_env = new_env;
	g_data.count = tmp;
}
