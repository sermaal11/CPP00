/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 02:36:31 by sergio            #+#    #+#             */
/*   Updated: 2025/07/13 02:40:52 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ************************************************************************** //
//                                                                            //
//                tests.cpp for GlobalBanksters United                        //
//                Created on  : Thu Nov 20 23:45:02 1989                      //
//                Last update : Wed Jan 04 09:23:52 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //

#include <vector>        // Para usar std::vector
#include <algorithm>     // Para std::for_each
#include <functional>    // Para std::mem_fun_ref
#include "../include/Account.hpp"  // Declaración de la clase Account

int main( void ) {

	// Alias de tipo: vector que contiene objetos Account
	typedef std::vector<Account::t> accounts_t;
	// Alias de tipo: vector que contiene enteros (para depósitos y retiradas)
	typedef std::vector<int> ints_t;
	// Pares de iteradores sincronizados: uno para cuentas y otro para ints
	typedef std::pair<accounts_t::iterator, ints_t::iterator> acc_int_t;

	// Array con montos iniciales para crear las cuentas
	int const amounts[] = { 42, 54, 957, 432, 1234, 0, 754, 16576 };
	size_t const amounts_size = sizeof(amounts) / sizeof(int);
	// Crear las cuentas iniciales con los valores anteriores
	accounts_t accounts(amounts, amounts + amounts_size);
	auto acc_begin = accounts.begin();
	auto acc_end   = accounts.end();

	// Array con cantidades que se ingresarán a cada cuenta
	int const d[] = { 5, 765, 564, 2, 87, 23, 9, 20 };
	size_t const d_size = sizeof(d) / sizeof(int);
	ints_t deposits(d, d + d_size);
	auto dep_begin = deposits.begin();
	auto dep_end   = deposits.end();

	// Array con cantidades que se intentarán retirar de cada cuenta
	int const w[] = { 321, 34, 657, 4, 76, 275, 657, 7654 };
	size_t const w_size = sizeof(w) / sizeof(int);
	ints_t withdrawals(w, w + w_size);
	auto wit_begin = withdrawals.begin();
	auto wit_end   = withdrawals.end();

	// Mostrar información global de todas las cuentas
	Account::displayAccountsInfos();
	// Mostrar el estado individual de cada cuenta
	std::for_each(acc_begin, acc_end, std::mem_fun_ref(&Account::displayStatus));

	// Aplicar los depósitos a las cuentas
	for (acc_int_t it(acc_begin, dep_begin);
		it.first != acc_end && it.second != dep_end;
		++(it.first), ++(it.second)) {
		(*it.first).makeDeposit(*it.second);
	}

	// Mostrar información global y por cuenta después de los depósitos
	Account::displayAccountsInfos();
	std::for_each(acc_begin, acc_end, std::mem_fun_ref(&Account::displayStatus));

	// Aplicar las retiradas a las cuentas
	for (acc_int_t it(acc_begin, wit_begin);
		it.first != acc_end && it.second != wit_end;
		++(it.first), ++(it.second)) {
		(*it.first).makeWithdrawal(*it.second);
	}

	// Mostrar información final global y por cuenta
	Account::displayAccountsInfos();
	std::for_each(acc_begin, acc_end, std::mem_fun_ref(&Account::displayStatus));

	return 0;
}

/*
🧠 Comentario general del flujo
Se crean 8 cuentas con saldos iniciales.
Se les aplica una serie de depósitos.
Luego, se intenta retirar dinero (algunas retiradas pueden fallar si no hay fondos).
Se muestran estadísticas globales e individuales después de cada fase.
*/

// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //
