/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_messages.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:13:32 by sadoming          #+#    #+#             */
/*   Updated: 2025/03/05 16:37:51 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_MESSAGES_H
# define ERROR_MESSAGES_H

/*		 ## ERRORS CONSTS ##		*/

# define MALLOC_ERROR	"Insuficient Memory or Malloc Error\n"

# define BAD_ARGS	"Error\nIncorrect number of arguments\n"
# define BAD_FILE	"Error\nThis file don't exist!\n"
# define BAD_EXT	"Error\nInvalid Extension\n"

# define BAD_MISS	"Error\nSome info is missing!\n"
# define BAD_DUP	"Error\nSome info is duplicated!\n"
# define BAD_INFO	"Error\nInvalid info encountered!\n"
# define BAD_CCOLOR	"Error\nInvalid Ceiling Color\n"
# define BAD_FCOLOR	"Error\nInvalid Floor Color\n"
# define BAD_MAP	"Error\nInvalid Map\n"

# define MAP_NOTCLOSED	"Invalid map, not closed properly\n"
# define INVALID_CHARS	"Invalid map, encountered invalid characters\n"
# define INVALID_MAP	"Invalid map, player is out of bounds\n"

# define BAD_PLY_NUM	"The file don't have/or have multiple player/s!\n"
# define PLY_TRSNMAP	"Player have traspased to an unexistent ubication\n"
/*	## ERRORS CONSTS END ##	*/

#endif
