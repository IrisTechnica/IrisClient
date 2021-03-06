#pragma once



namespace HLSLDisassembler
{
	enum class SyncFlags
	{
		None,

		ThreadsInGroup = 1,
		SharedMemory = 2,
		UnorderedAccessViewGroup = 4,
		UnorderedAccessViewGlobal = 8
	};

	std::string ToString(SyncFlags value);
};