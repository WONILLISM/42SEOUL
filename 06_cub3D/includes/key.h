/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wopark <wopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 13:55:21 by wopark            #+#    #+#             */
/*   Updated: 2021/04/14 13:58:23 by wopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_H
# define KEY_H

# define KEY_A	0
# define KEY_S	1
# define KEY_D	2
# define KEY_F	3
# define KEY_G	4
# define KEY_Z	6
# define KEY_X	7
# define KEY_C	8
# define KEY_V	9
# define KEY_B	11
# define KEY_Q	12
# define KEY_W	13
# define KEY_E	14
# define KEY_R	15
# define KEY_Y	16
# define KEY_T	17
# define KEY_1	18
# define KEY_2	19
# define KEY_3	20
# define KEY_4	21
# define KEY_6	22
# define KEY_5	23
# define KEY_PLUS	24
# define KEY_9	25
# define KEY_7	26
# define KEY_MINUS	27
# define KEY_8	28
# define KEY_0	29
# define KEY_ESC 53
# define KEY_SHIFT 57
# define KEY_UP		126
# define KEY_DOWN	125
# define KEY_LEFT	123
# define KEY_RIGTH	124

typedef struct	s_key
{
	int			w;
	int			s;
	int			a;
	int			d;
	int			up;
	int			down;
	int			left;
	int			right;
}				t_key;

#endif
