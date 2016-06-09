#pragma once

#include "cbase.h"
#include "mom_replay_data.h"
#include "util/serialization.h"

class CMomReplayBase :
	public ISerializable
{
protected:
	CMomReplayBase(CReplayHeader header) :
		m_rhHeader(header)
	{
	}

public:
	virtual ~CMomReplayBase() {}

public:
	// All these are virtual so they can be overriden in later versions.
	virtual const char* GetMapName() { return m_rhHeader.m_szMapName; }
	virtual const char* GetPlayerName() { return m_rhHeader.m_szPlayerName; }
	virtual uint64 GetPlayerSteamID() { return m_rhHeader.m_ulSteamID; }
	virtual float GetTickInterval() { return m_rhHeader.m_fTickInterval; }
	virtual float GetRunTime() { return m_rhHeader.m_fRunTime; }
	virtual int GetRunFlags() { return m_rhHeader.m_iRunFlags; }

public:
	virtual void SetMapName(const char* name) { Q_strcpy(m_rhHeader.m_szMapName, name); }
	virtual void SetPlayerName(const char* name) { Q_strcpy(m_rhHeader.m_szPlayerName, name); }
	virtual void SetPlayerSteamID(uint64 steamID) { m_rhHeader.m_ulSteamID = steamID; }
	virtual void SetTickInterval(float interval) { m_rhHeader.m_fTickInterval = interval; }
	virtual void SetRunTime(float runTime) { m_rhHeader.m_fRunTime = runTime; }
	virtual void SetRunFlags(int runFlags) { m_rhHeader.m_iRunFlags = runFlags; }

public:
	virtual uint8 GetVersion() = 0;
	virtual CMomRunStats* GetRunStats() = 0;
	virtual int32 GetFrameCount() = 0;
	virtual CReplayFrame* GetFrame(int32 index) = 0;
	virtual void AddFrame(const CReplayFrame& frame) = 0;
	virtual bool SetFrame(int32 index, const CReplayFrame& frame) = 0;
	virtual CMomRunStats* CreateRunStats(uint8 stages) = 0;

protected:
	CReplayHeader m_rhHeader;
};