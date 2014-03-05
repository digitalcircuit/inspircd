/*
 * InspIRCd -- Internet Relay Chat Daemon
 *
 *   Copyright (C) 2009 Daniel De Graaf <danieldg@inspircd.org>
 *   Copyright (C) 2007 Robin Burchell <robin+git@viroteck.net>
 *
 * This file is part of InspIRCd.  InspIRCd is free software: you can
 * redistribute it and/or modify it under the terms of the GNU General Public
 * License as published by the Free Software Foundation, version 2.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */


#include "inspircd.h"

/** Handle /LINKS.
 */
class CommandLinks : public Command
{
 public:
	/** Constructor for links.
	 */
	CommandLinks ( Module* parent) : Command(parent,"LINKS",0,0) { }
	/** Handle command.
	 * @param parameters The parameters to the command
	 * @param user The user issuing the command
	 * @return A value from CmdResult to indicate command success or failure.
	 */
	CmdResult Handle(const std::vector<std::string>& parameters, User *user);
};

/** Handle /LINKS
 */
CmdResult CommandLinks::Handle (const std::vector<std::string>&, User *user)
{
	user->WriteNumeric(RPL_LINKS, "%s %s :0 %s", ServerInstance->Config->ServerName.c_str(),ServerInstance->Config->ServerName.c_str(),ServerInstance->Config->ServerDesc.c_str());
	user->WriteNumeric(RPL_ENDOFLINKS, "* :End of /LINKS list.");
	return CMD_SUCCESS;
}

COMMAND_INIT(CommandLinks)