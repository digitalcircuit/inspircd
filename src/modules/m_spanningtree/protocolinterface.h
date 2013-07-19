/*
 * InspIRCd -- Internet Relay Chat Daemon
 *
 *   Copyright (C) 2008 Craig Edwards <craigedwards@brainbox.cc>
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


#pragma once

class SpanningTreeProtocolInterface : public ProtocolInterface
{
 public:
	bool SendEncapsulatedData(const parameterlist &encap);
	void SendMetaData(Extensible* target, const std::string &key, const std::string &data);
	void SendTopic(Channel* channel, std::string &topic);
	void SendMode(User* source, User* usertarget, Channel* chantarget, const parameterlist& modedata, const std::vector<TranslateType>& types);
	void SendSNONotice(const std::string &snomask, const std::string &text);
	void PushToClient(User* target, const std::string &rawline);
	void SendMessage(Channel* target, char status, const std::string& text, MessageType msgtype);
	void SendMessage(User* target, const std::string& text, MessageType msgtype);
	void GetServerList(ServerList& sl);
};
