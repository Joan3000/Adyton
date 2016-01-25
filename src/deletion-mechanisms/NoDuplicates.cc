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


#ifndef NODUPLICATES_H
	#define NODUPLICATES_H
	#include "NoDuplicates.h"
#endif

/* Constructor
 * -------------
 * Every node has a "NoDuplicates" component. Every component is the same for all nodes
 * and uses a set to store all packets delivered to the current node. Each node holds
 * only the packets delivered to this node.  
 */
NoDuplicates::NoDuplicates(int NID): DeletionMechanism()
{
	ID=NID;
	Delivered.clear();
	return;
}

NoDuplicates::~NoDuplicates()
{
	return;
}

/* setAsDelivered
 * --------------
 * This method is called when a packet that is destined to current node is delivered
 * successfully. The received packet is inserted to the "Delivered" set for future 
 * reference.
 */
void NoDuplicates::setAsDelivered(int pktID)
{
	if(isDelivered(pktID))
	{
		return;
	}
	this->Delivered.insert(pktID);
	return;
}

/* CleanBuffer
 * -----------
 * Is not used by "NoDuplicates".
 */
void NoDuplicates::CleanBuffer(PacketBuffer* PktBf)
{
	return;
}

/* UpdateInfo
 * ----------
 * Is not used by "NoDuplicates".
 */
void NoDuplicates::UpdateInfo(int* info)
{
	return;
}

/* GetInfo
 * -------
 * Is not used by "NoDuplicates".
 */
int* NoDuplicates::GetInfo(void)
{
	return NULL;
}

/* OffloaderDeletePkt
 * ------------------
 * Returns if the offloading node (last hop node that transmits pkt to its destination)
 * should drop the packet.
 */
bool NoDuplicates::OffloaderDeletePkt(void )
{
	return true;
}

/* DestinationDeletePkt
 * --------------------
 * Returns if the destination node should drop the packet.
 */
bool NoDuplicates::DestinationDeletePkt(void )
{
	return true;
}

/* ExchangeDirectSummary
 * ---------------------
 * Returns if a summary containing information about packets destined to the node
 * in contact should be exchanged or not.
 */
bool NoDuplicates::ExchangeDirectSummary(void )
{
	return true;
}

/* isDelivered
 * -----------
 * Returns if the packet with id PID has been already received by the current node.
 * This is information is available in the "Delivered" set.
 */
bool NoDuplicates::isDelivered(int PID)
{
	set<int>::iterator it=Delivered.find(PID);
	if(it == Delivered.end())
	{
		return false;
	}
	else
	{
		return true;
	}
}

/* NoDuplicatesSupport
 * -------------------
 * Returns if the deletion mechanism is designed not to transmit a duplicate to the
 * destination node in case that the destination node has already received a packet 
 * replica.
 */
bool NoDuplicates::NoDuplicatesSupport(void )
{
	return true;
}
