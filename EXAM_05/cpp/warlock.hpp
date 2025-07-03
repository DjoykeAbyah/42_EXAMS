/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   warlock.hpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/02 16:58:12 by dreijans      #+#    #+#                 */
/*   Updated: 2025/07/03 19:55:24 by djoyke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Warlock {
	
	private:

		std::string _name;
		std::string _title;
	
	public:
	
		Warlock() = delete;
		Warlock(std::string name, std::string title);
		Warlock(const Warlock &copy) = delete;
		Warlock& operator=(const Warlock &copy) = delete;
		~Warlock();

		const std::string& getName() const;
		const std::string& getTitle() const;
		void setTitle(const std::string &title);

		void introduce() const;
};
