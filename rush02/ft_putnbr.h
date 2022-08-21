/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 16:16:03 by hucorrei          #+#    #+#             */
/*   Updated: 2022/08/21 16:26:25 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUTNBR_H
# define FT_PUTNBR_H

void	ft_put_thousand(int size, char ***dict);
void	ft_print_hundred(char *nbr, int size, char ***dict);
void	ft_print_ten(char *nbr, int size, char ***dict);
void	ft_put_digit(char *nbr, int size, char ***dict);
#endif
