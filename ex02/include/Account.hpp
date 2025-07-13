/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 20:22:06 by sergio            #+#    #+#             */
/*   Updated: 2025/07/13 01:25:32 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ************************************************************************** //
//                                                                            //
//                Account.hpp for GlobalBanksters United                      //
//                Created on  : Thu Nov 20 19:43:15 1989                      //
//                Last update : Wed Jan 04 14:54:06 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //

#pragma once
#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

// ************************************************************************** //
//                               Account Class                                //
// ************************************************************************** //

class Account 
{
	private:
		static int	_nbAccounts;			// Total de cuentas creadas
		static int	_totalAmount;			// Suma total de dinero en todas las cuentas
		static int	_totalNbDeposits;		// Número total de depósitos globales
		static int	_totalNbWithdrawals;	// Número total de retiradas globales

		static void	_displayTimestamp( void );	// Muestra un timestamp al imprimir logs

		int			_accountIndex;			// Índice único de esta cuenta
		int			_amount;				// Saldo actual de la cuenta
		int			_nbDeposits;			// Depósitos realizados en esta cuenta
		int			_nbWithdrawals;			// Retiradas realizadas en esta cuenta

		Account( void );					// Constructor por defecto (privado)

	public:
		typedef Account		t;				// Alias de tipo interno

		static int	getNbAccounts( void );			// Devuelve el número total de cuentas
		static int	getTotalAmount( void );			// Devuelve el total de dinero acumulado
		static int	getNbDeposits( void );			// Devuelve el número total de depósitos
		static int	getNbWithdrawals( void );		// Devuelve el número total de retiradas
		static void	displayAccountsInfos( void );	// Imprime resumen global del sistema

		Account( int initial_deposit );		// Constructor con depósito inicial
		~Account( void );					// Destructor de la cuenta

		void	makeDeposit( int deposit );			// Realiza un depósito y actualiza datos
		bool	makeWithdrawal( int withdrawal );	// Intenta retirar dinero (true/false)
		int		checkAmount( void ) const;			// Devuelve el saldo actual (sin modificar)
		void	displayStatus( void ) const;		// Imprime estado de esta cuenta
};


// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //

#endif /* __ACCOUNT_H__ */
