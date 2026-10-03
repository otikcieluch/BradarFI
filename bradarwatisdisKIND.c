//a list of the extensions
#include <string.h>   
#include <strings.h>  
#include "bradarwatisdisKIND.h"

const char *kind(const char *name)
{
	//file types a lot of 'em
	const char *dot = strrchr(name, '.');
	if (!dot) return "unknown/empty";
	//goats
	if (!strcasecmp(dot, ".c"))       return "C source file";
	if (!strcasecmp(dot, ".h"))       return "C header file";
	
	if (!strcasecmp(dot, ".cpp"))     return "C++ source file";
	if (!strcasecmp(dot, ".hpp"))     return "C++ header file";
	if (!strcasecmp(dot, ".rs"))      return "Rust source file";
	if (!strcasecmp(dot, ".go"))      return "Go source file";
	if (!strcasecmp(dot, ".java"))    return "Java source file";
	if (!strcasecmp(dot, ".kt"))      return "Kotlin source file";
	if (!strcasecmp(dot, ".py"))      return "Python source file";
	if (!strcasecmp(dot, ".js"))      return "JavaScript file";
	if (!strcasecmp(dot, ".ts"))      return "TypeScript file";
	if (!strcasecmp(dot, ".jsx"))     return "JavaScript React file";
	if (!strcasecmp(dot, ".tsx"))     return "TypeScript React file";
	if (!strcasecmp(dot, ".php"))     return "PHP file";
	if (!strcasecmp(dot, ".rb"))      return "Ruby source file";
	if (!strcasecmp(dot, ".swift"))   return "Swift source file";
	if (!strcasecmp(dot, ".dart"))    return "Dart source file";
	if (!strcasecmp(dot, ".lua"))     return "Lua source file";
	if (!strcasecmp(dot, ".sql"))     return "SQL file";

	if (!strcasecmp(dot, ".sh"))      return "shell script";
	if (!strcasecmp(dot, ".bash"))    return "Bash script";
	if (!strcasecmp(dot, ".zsh"))     return "Zsh script";
	if (!strcasecmp(dot, ".fish"))    return "Fish shell script";
	if (!strcasecmp(dot, ".ps1"))     return "PowerShell script";
	if (!strcasecmp(dot, ".bat"))     return "Windows batch file";

	if (!strcasecmp(dot, ".html"))    return "HTML document";
	if (!strcasecmp(dot, ".css"))     return "CSS stylesheet";
	if (!strcasecmp(dot, ".scss"))    return "SCSS stylesheet";

	if (!strcasecmp(dot, ".json"))    return "JSON file";
	if (!strcasecmp(dot, ".yaml"))    return "YAML file";
	if (!strcasecmp(dot, ".yml"))     return "YAML file";
	if (!strcasecmp(dot, ".toml"))    return "TOML configuration file";
	if (!strcasecmp(dot, ".xml"))     return "XML file";
	if (!strcasecmp(dot, ".ini"))     return "INI configuration file";
	if (!strcasecmp(dot, ".cfg"))     return "configuration file";
	if (!strcasecmp(dot, ".conf"))    return "configuration file";
	if (!strcasecmp(dot, ".env"))     return "environment file";
	if (!strcasecmp(dot, ".csv"))     return "CSV file";
	if (!strcasecmp(dot, ".txt"))     return "text file";
	if (!strcasecmp(dot, ".md"))      return "Markdown file";

	if (!strcasecmp(dot, ".png"))     return "PNG image";
	if (!strcasecmp(dot, ".jpg"))     return "JPEG image";
	if (!strcasecmp(dot, ".jpeg"))    return "JPEG image";
	if (!strcasecmp(dot, ".webp"))    return "WebP image";
	if (!strcasecmp(dot, ".avif"))    return "AVIF image";
	if (!strcasecmp(dot, ".gif"))     return "GIF image";
	if (!strcasecmp(dot, ".svg"))     return "SVG image";
	if (!strcasecmp(dot, ".ico"))     return "icon image";

	if (!strcasecmp(dot, ".mp3"))     return "MP3 audio";
	if (!strcasecmp(dot, ".wav"))     return "WAV audio";
	if (!strcasecmp(dot, ".flac"))    return "FLAC audio";
	if (!strcasecmp(dot, ".ogg"))     return "Ogg audio";
	if (!strcasecmp(dot, ".opus"))    return "Opus audio";
	if (!strcasecmp(dot, ".m4a"))     return "MPEG-4 audio";
	if (!strcasecmp(dot, ".aac"))     return "AAC audio";

	if (!strcasecmp(dot, ".mp4"))     return "MP4 video";
	if (!strcasecmp(dot, ".mkv"))     return "Matroska video";
	if (!strcasecmp(dot, ".webm"))    return "WebM video";
	if (!strcasecmp(dot, ".mov"))     return "QuickTime video";

	if (!strcasecmp(dot, ".zip"))     return "ZIP archive";
	if (!strcasecmp(dot, ".7z"))      return "7-Zip archive";
	if (!strcasecmp(dot, ".rar"))     return "RAR archive";
	if (!strcasecmp(dot, ".tar"))     return "TAR archive";
	if (!strcasecmp(dot, ".gz"))      return "Gzip compressed file";
	if (!strcasecmp(dot, ".xz"))      return "XZ compressed file";
	if (!strcasecmp(dot, ".zst"))     return "Zstandard compressed file";

	if (!strcasecmp(dot, ".pdf"))     return "PDF document";
	if (!strcasecmp(dot, ".docx"))    return "Word document";
	if (!strcasecmp(dot, ".xlsx"))    return "Excel spreadsheet";
	if (!strcasecmp(dot, ".pptx"))    return "PowerPoint presentation";
	if (!strcasecmp(dot, ".odt"))     return "OpenDocument text document";
	if (!strcasecmp(dot, ".ods"))     return "OpenDocument spreadsheet";
	if (!strcasecmp(dot, ".odp"))     return "OpenDocument presentation";

	if (!strcasecmp(dot, ".iso"))     return "ISO disk image";
	if (!strcasecmp(dot, ".img"))     return "disk image";
	if (!strcasecmp(dot, ".vhdx"))    return "virtual hard disk";
	if (!strcasecmp(dot, ".vmdk"))    return "VMware virtual disk";
	if (!strcasecmp(dot, ".vdi"))     return "VirtualBox disk image";
	if (!strcasecmp(dot, ".qcow2"))   return "QEMU virtual disk";

	if (!strcasecmp(dot, ".deb"))     return "Debian package";
	if (!strcasecmp(dot, ".rpm"))     return "RPM package";
	if (!strcasecmp(dot, ".appimage")) return "AppImage executable";
	if (!strcasecmp(dot, ".exe"))     return "Windows executable";
	if (!strcasecmp(dot, ".msi"))     return "Windows installer";
	if (!strcasecmp(dot, ".dll"))     return "Windows dynamic library";
	if (!strcasecmp(dot, ".so"))      return "Linux shared library";

	if (!strcasecmp(dot, ".ttf"))     return "TrueType font";
	if (!strcasecmp(dot, ".otf"))     return "OpenType font";
	if (!strcasecmp(dot, ".woff"))    return "Web font";
	if (!strcasecmp(dot, ".woff2"))   return "Web font";
	//My hand hurts
	return "unknown/empty";
}
