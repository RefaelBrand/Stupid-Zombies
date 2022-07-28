#pragma once

#include "Menu.h"

class Manager
{

protected:
	unique_ptr<Menu> m_menu;
	unique_ptr<Manager> m_manager;

public:
	Manager(unique_ptr<Menu> menu, unique_ptr<Manager> manager)
		:m_menu(std::move(menu)), m_manager(std::move(manager)) {}

	virtual ~Manager() = 0{};

	virtual void run()								{ m_menu->run(); }
	virtual void run(unsigned id)					{ m_menu->run(); }
	virtual void runManager()						{ m_manager->run(); };
	virtual void runManager(unsigned id)			{ m_manager->run(); };
};