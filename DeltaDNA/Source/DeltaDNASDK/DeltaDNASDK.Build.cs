using UnrealBuildTool;
using System.IO;
using System;

public class DeltaDNASDK : ModuleRules
{
	public DeltaDNASDK(TargetInfo Target)
	{
		Type = ModuleType.External;

		string sdkPath = Path.GetDirectoryName(RulesCompiler.GetModuleFilename(this.GetType().Name));
		PublicIncludePaths.Add(Path.Combine(sdkPath, "include"));

		if (Target.Platform == UnrealTargetPlatform.IOS)
        {
			string configuration = Target.Configuration == UnrealTargetConfiguration.DebugGame ? "Debug" : "Release";

			string libPath = Path.Combine(sdkPath, "lib", configuration);
            string libFilePath = Path.Combine(libPath, "libDeltaDNASDK.a");

            PublicAdditionalLibraries.Add(libFilePath);
            PublicAdditionalShadowFiles.Add(libFilePath);
        }
    }
}
