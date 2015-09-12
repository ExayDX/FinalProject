

#include "SimpleMaterialPrivatePCH.h"


class SimpleMaterialShader : public FShader
{
	DECLARE_SHADER_TYPE(SimpleMaterialShader, Material)

public:
	static bool ShouldCache(EShaderPlatform Platform);

	SimpleMaterialShader(const ShaderMetaType::CompiledShaderInitializerType& Initializer);
	SimpleMaterialShader() {}
};