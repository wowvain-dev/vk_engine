# shader_compiler.ps1

param (
    [String]$SourceFile,
    [String]$OutputDir
)


$GlslangValidator = "I:/VulkanSDK/Bin/glslangValidator.exe"
$FileNameWithoutExtension = [System.IO.Path]::GetFileNameWithoutExtension($SourceFile)
$OutputFile = Join-Path $OutputDir "$FileNameWithoutExtension.spv"

Write-Host "Compiling shader: $SourceFile -> $OutputFile"
& $GlslangValidator -V $SourceFile -o $OutputFile