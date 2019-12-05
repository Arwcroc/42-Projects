/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tovalid.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 14:19:11 by tefroiss          #+#    #+#             */
/*   Updated: 2019/12/03 18:25:09 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



/*
**	Une specification de conversion se compose de champs facultatifs et
**	obligatoires mis en forme comme suit :
**	%[flags][width][.precision][size]type
**
**	Flags :
**	- = aligner a gauche le resultat selon la largeur de champ donnee				--> KO
**	0 = Si width est prefixe par 0, des zeros non significatifs sont ajoutes		--> KO
**	jusqu'a ce que la largeur minimale soit atteinte. Si 0 et - apparaissent,
**	0 est ignore.
**  * = si width = *, alors le prochain argument definit width.						--> KO
**
**	Width : largeur de l'output - si elle est superieure a l'output, on
**	complete avec des espaces pour fill (ou des 0 si un seul flag = 0)
**
**	Precision :
**	. = suivi d'un entier decimal positif qui selon le type de conversion,
**	va affecter differemment l'output.
**		c -> aucun effet
**		s -> nombre max de caracteres a imprimer
**		d, i, u, x, X -> nombre min de chiffres a imprimer (par defaut a un)
**		si le nombre de chiffres de l'arg est inferieur a precision, la valeur
**		de sortie est remplie a gauche de 0 (si precision = 0 et valeur a
**		convertir = 0 -> pas d'output).
**
**	Type :
**	c = Character;																	--> KO
**	s =	String;																		--> KO
**	p =	Pointer Type -> output arg under the form of an adress						--> KO
**		containing hexadecimal numbers;
**	d = Int decimal;																--> KO
**	i = same as d;																	--> KO
**	u = Unsigned int;																--> KO
**	x = Hexadecimal number (abcdef);												--> KO
**	X = Hexadecimal number (ABCDEF);												--> KO
**	% = 2 % a la suite affiche un %													--> KO
**
**	ETAPE 1 : ARRIVER A CHOPPER LA BONNE CONVERSION;								--> KO
**	ETAPE 2 : GESTION DE LA WIDTH;		 											--> KO
**	ETAPE 3 : GESTION DES FLAGS;													--> KO
**	ETAPE 4 ; GESTION DE LA PRECISION;												--> KO
**	ETAPE 5 : GESTION D'ERREURS;													--> KO
**	ETAPE INTERMEDIAIRE GERER LE PRINT DANS FORMAT;									--> KO
**	ETAPE 6 : GERER PLUSIEURS ARGUMENTS;											--> KO
**	ETAPE 7 : PROFIT!;																--> KO
*/