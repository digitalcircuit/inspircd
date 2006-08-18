/*       +------------------------------------+
 *       | Inspire Internet Relay Chat Daemon |
 *       +------------------------------------+
 *
 *  InspIRCd is copyright (C) 2002-2006 ChatSpike-Dev.
 *                       E-mail:
 *                <brain@chatspike.net>
 *                <Craig@chatspike.net>
 *
 * Written by Craig Edwards, Craig McLure, and others.
 * This program is free but copyrighted software; see
 *            the file COPYING for details.
 *
 * ---------------------------------------------------
 */

using namespace std;

#include "inspircd_config.h"
#include "inspircd.h"
#include "inspircd_io.h"
#include <time.h>
#include <string>
#include <ext/hash_map>
#include <map>
#include <sstream>
#include <vector>
#include <deque>
#include "users.h"
#include "ctables.h"
#include "globals.h"
#include "modules.h"
#include "dynamic.h"
#include "wildcard.h"
#include "message.h"
#include "commands.h"
#include "mode.h"
#include "xline.h"
#include "inspstring.h"
#include "dnsqueue.h"
#include "helperfuncs.h"
#include "hashcomp.h"
#include "socketengine.h"
#include "typedefs.h"
#include "command_parse.h"
#include "cmd_userhost.h"

extern ServerConfig* Config;
extern InspIRCd* ServerInstance;
extern int MODCOUNT;
extern std::vector<Module*> modules;
extern std::vector<ircd_module*> factory;
extern time_t TIME;
extern user_hash clientlist;
extern chan_hash chanlist;
extern std::vector<userrec*> all_opers;
extern std::vector<userrec*> local_users;
extern userrec* fd_ref_table[MAX_DESCRIPTORS];

void cmd_userhost::Handle (char **parameters, int pcnt, userrec *user)
{
	char Return[MAXBUF],junk[MAXBUF];
	snprintf(Return,MAXBUF,"302 %s :",user->nick);
	
	for (int i = 0; i < pcnt; i++)
	{
		userrec *u = Find(parameters[i]);
		if ((u) && (u->registered == 7))
		{
			if(*u->oper)
				if(*user->oper)
					snprintf(junk,MAXBUF,"%s*=+%s@%s ",u->nick,u->ident,u->host);
				else
					snprintf(junk,MAXBUF,"%s*=+%s@%s ",u->nick,u->ident,u->dhost);
			else
				if(*user->oper)
					snprintf(junk,MAXBUF,"%s=+%s@%s ",u->nick,u->ident,u->host);
				else
					snprintf(junk,MAXBUF,"%s=+%s@%s ",u->nick,u->ident,u->dhost);

			strlcat(Return,junk,MAXBUF);
		}
	}
	WriteServ(user->fd,Return);
}



