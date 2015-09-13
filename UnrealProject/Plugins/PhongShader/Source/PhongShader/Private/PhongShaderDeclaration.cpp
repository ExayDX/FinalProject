#include "PhongShaderPrivatePCH.h"
#include "PhongShaderDeclaration.h"

//#include "ShaderParameterUtils.h"
//#include "RHIStaticStates.h"
//
////These are needed to actually implement the constant buffers so they are available inside our shader
////They also need to be unique over the entire solution since they can in fact be accessed from any shader
//IMPLEMENT_UNIFORM_BUFFER_STRUCT(FPhongShaderConstantParameters, TEXT("PSConstants"))
//IMPLEMENT_UNIFORM_BUFFER_STRUCT(FPhongShaderVariableParameters, TEXT("PSVariables"))
//
//FPhongShaderDeclaration::FPhongShaderDeclaration(const ShaderMetaType::CompiledShaderInitializerType& Initializer)
//: FGlobalShader(Initializer)
//{
//	//This call is what lets the shader system know that the surface OutputSurface is going to be available in the shader. The second parameter is the name it will be known by in the shader
//	TextureParameter.Bind(Initializer.ParameterMap, TEXT("TextureParameter"));  //The text parameter here is the name of the parameter in the shader
//}
//
//void FPhongShaderDeclaration::SetUniformBuffers(FRHICommandList& RHICmdList, FPhongShaderConstantParameters& ConstantParameters, FPhongShaderVariableParameters& VariableParameters)
//{
//	FPhongShaderConstantParametersRef ConstantParametersBuffer;
//	FPhongShaderVariableParametersRef VariableParametersBuffer;
//
//	ConstantParametersBuffer = FPhongShaderConstantParametersRef::CreateUniformBufferImmediate(ConstantParameters, UniformBuffer_SingleDraw);
//	VariableParametersBuffer = FPhongShaderVariableParametersRef::CreateUniformBufferImmediate(VariableParameters, UniformBuffer_SingleDraw);
//
//	SetUniformBufferParameter(RHICmdList, GetPixelShader(), GetUniformBufferParameter<FPhongShaderConstantParameters>(), ConstantParametersBuffer);
//	SetUniformBufferParameter(RHICmdList, GetPixelShader(), GetUniformBufferParameter<FPhongShaderVariableParameters>(), VariableParametersBuffer);
//}
//
//void FPhongShaderDeclaration::SetSurfaces(FRHICommandList& RHICmdList, FShaderResourceViewRHIRef TextureParameterSRV)
//{
//	FPixelShaderRHIParamRef PixelShaderRHI = GetPixelShader();
//
//	if (TextureParameter.IsBound())   //This actually sets the shader resource view to the texture parameter in the shader :)
//		RHICmdList.SetShaderResourceViewParameter(PixelShaderRHI, TextureParameter.GetBaseIndex(), TextureParameterSRV);
//}
//
//void FPhongShaderDeclaration::UnbindBuffers(FRHICommandList& RHICmdList)
//{
//	FPixelShaderRHIParamRef PixelShaderRHI = GetPixelShader();
//
//	if (TextureParameter.IsBound())
//		RHICmdList.SetShaderResourceViewParameter(PixelShaderRHI, TextureParameter.GetBaseIndex(), FShaderResourceViewRHIParamRef());
//}
//
////This is what will instantiate the shader into the engine from the engine/Shaders folder
////                      ShaderType               ShaderFileName     Shader function name            Type
//IMPLEMENT_SHADER_TYPE(, FVertexShaderExample, TEXT("Phong_VS_PS"), TEXT("PhongVS"), SF_Vertex);
//IMPLEMENT_SHADER_TYPE(, FPhongShaderDeclaration, TEXT("Phong_VS_PS"), TEXT("PhongPS"), SF_Pixel);
//
////Needed to make sure the plugin works :)
//IMPLEMENT_MODULE(FDefaultModuleImpl, PixelShader)