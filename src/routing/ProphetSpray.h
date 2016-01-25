/*
 *  Adyton: A Network Simulator for Opportunistic Networks
 *  Copyright (C) 2015, 2016  Nikolaos Papanikos, Dimitrios-Georgios Akestoridis,
 *  and Evangelos Papapetrou
 *
 *  This file is part of Adyton.
 *
 *  Adyton is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  Adyton is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with Adyton.  If not, see <http://www.gnu.org/licenses/>.
 *
 *  Written by Nikolaos Papanikos.
 */


#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <math.h>

#ifndef ROUTING_H
	#define ROUTING_H
	#include "Routing.h"
#endif

#ifndef ADJA_H
	#define ADJA_H
	#include "../data-structures/Adjacency.h"
#endif

#ifndef DPT_H
	#define DPT_H
	#include "../data-structures/DPT.h"
#endif

class ProphetSpray:public Routing
{
public:
	ProphetSpray(PacketPool* PP, MAC* mc, PacketBuffer* Bf,int NID,Statistics *St,Settings *S,God *G);
	~ProphetSpray();
	virtual void recv(double rTime,int pktID);
	virtual void NewContact(double CTime,int NID);
	virtual void ContactRemoved(double CTime,int NID);
	virtual void Contact(double CTime,int NID);
protected:
	DPT *MyDPT;
	double *RepValues;
	virtual void SendPacket(double STime, int pktID,int nHop,int RepValue);
	virtual void AfterDirectTransfers(double CTime,int NID);
private:
	void ReceptionData(Header *hd,Packet *pkt,int PID,double CurrentTime,int RealID);
	void ReceptionRequestContacts(Header *hd,Packet *pkt,int PID,double CurrentTime);
	void ReceptionDPT(Header *hd,Packet *pkt,int PID,double CurrentTime);
	void ReceptionSummary(Header *hd,Packet *pkt,int PID,double CurrentTime);
	void ReceptionRequest(Header *hd,Packet *pkt,int PID,double CurrentTime);
};
