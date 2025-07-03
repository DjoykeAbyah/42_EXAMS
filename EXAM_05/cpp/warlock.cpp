/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   warlock.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: djoyke <djoyke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/03 19:50:12 by djoyke        #+#    #+#                 */
/*   Updated: 2025/07/03 20:27:08 by djoyke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "warlock.hpp"

Warlock::Warlock(std::string name, std::string title) {
	_name = name;
	setTitle(title);
	std::cout << _name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock() {
	std::cout << _name << ": My job here is done!" << std::endl;
}

const std::string& Warlock::getName() const {
	return _name;
}

const std::string& Warlock::getTitle() const {
	return _title;
}

void Warlock::setTitle(const std::string &title) {
	_title = title;
}

void Warlock::introduce() const {
	std::cout << _name << ": I am " << _name << ", " << _title << "!" << std::endl;
}

