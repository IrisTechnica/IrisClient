#pragma once


#include "../../Util/BytecodeReader.h"
#include "ProgramType.h"

namespace HLSLDisassembler
{
	class ShaderVersion
	{
	public :
		static ShaderVersion ParseRdef(BytecodeReader& reader);
		static ShaderVersion ParseShex(BytecodeReader& reader);

		uint8_t GetMajorVersion() const;
		uint8_t GetMinorVersion() const;
		ProgramType GetProgramType() const;

	private :
		ShaderVersion() { }

		uint8_t _majorVersion;
		uint8_t _minorVersion;
		ProgramType _programType;
	};
};