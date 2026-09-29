#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>


static const char *kind(const char *name)
{
	//file types a lot of 'em
	const char *dot = strrchr(name, '.');
	if (!dot) return "unknown/directory/empty";
	if (!strcmp(dot, ".c"))       return "C source file";
	if (!strcmp(dot, ".h"))       return "C header file";
	if (!strcmp(dot, ".cpp"))     return "C++ source file";
	if (!strcmp(dot, ".hpp"))     return "C++ header file";
	if (!strcmp(dot, ".rs"))      return "Rust source file";
	if (!strcmp(dot, ".go"))      return "Go source file";
	if (!strcmp(dot, ".java"))    return "Java source file";
	if (!strcmp(dot, ".kt"))      return "Kotlin source file";
	if (!strcmp(dot, ".py"))      return "Python source file";
	if (!strcmp(dot, ".js"))      return "JavaScript file";
	if (!strcmp(dot, ".ts"))      return "TypeScript file";
	if (!strcmp(dot, ".jsx"))     return "JavaScript React file";
	if (!strcmp(dot, ".tsx"))     return "TypeScript React file";
	if (!strcmp(dot, ".php"))     return "PHP file";
	if (!strcmp(dot, ".rb"))      return "Ruby source file";
	if (!strcmp(dot, ".swift"))   return "Swift source file";
	if (!strcmp(dot, ".dart"))    return "Dart source file";
	if (!strcmp(dot, ".lua"))     return "Lua source file";
	if (!strcmp(dot, ".sql"))     return "SQL file";

	if (!strcmp(dot, ".sh"))      return "shell script";
	if (!strcmp(dot, ".bash"))    return "Bash script";
	if (!strcmp(dot, ".zsh"))     return "Zsh script";
	if (!strcmp(dot, ".fish"))    return "Fish shell script";
	if (!strcmp(dot, ".ps1"))     return "PowerShell script";
	if (!strcmp(dot, ".bat"))     return "Windows batch file";

	if (!strcmp(dot, ".html"))    return "HTML document";
	if (!strcmp(dot, ".css"))     return "CSS stylesheet";
	if (!strcmp(dot, ".scss"))    return "SCSS stylesheet";

	if (!strcmp(dot, ".json"))    return "JSON file";
	if (!strcmp(dot, ".yaml"))    return "YAML file";
	if (!strcmp(dot, ".yml"))     return "YAML file";
	if (!strcmp(dot, ".toml"))    return "TOML configuration file";
	if (!strcmp(dot, ".xml"))     return "XML file";
	if (!strcmp(dot, ".ini"))     return "INI configuration file";
	if (!strcmp(dot, ".cfg"))     return "configuration file";
	if (!strcmp(dot, ".conf"))    return "configuration file";
	if (!strcmp(dot, ".env"))     return "environment file";
	if (!strcmp(dot, ".csv"))     return "CSV file";
	if (!strcmp(dot, ".txt"))     return "text file";
	if (!strcmp(dot, ".md"))      return "Markdown file";

	if (!strcmp(dot, ".png"))     return "PNG image";
	if (!strcmp(dot, ".jpg"))     return "JPEG image";
	if (!strcmp(dot, ".jpeg"))    return "JPEG image";
	if (!strcmp(dot, ".webp"))    return "WebP image";
	if (!strcmp(dot, ".avif"))    return "AVIF image";
	if (!strcmp(dot, ".gif"))     return "GIF image";
	if (!strcmp(dot, ".svg"))     return "SVG image";
	if (!strcmp(dot, ".ico"))     return "icon image";

	if (!strcmp(dot, ".mp3"))     return "MP3 audio";
	if (!strcmp(dot, ".wav"))     return "WAV audio";
	if (!strcmp(dot, ".flac"))    return "FLAC audio";
	if (!strcmp(dot, ".ogg"))     return "Ogg audio";
	if (!strcmp(dot, ".opus"))    return "Opus audio";
	if (!strcmp(dot, ".m4a"))     return "MPEG-4 audio";
	if (!strcmp(dot, ".aac"))     return "AAC audio";

	if (!strcmp(dot, ".mp4"))     return "MP4 video";
	if (!strcmp(dot, ".mkv"))     return "Matroska video";
	if (!strcmp(dot, ".webm"))    return "WebM video";
	if (!strcmp(dot, ".mov"))     return "QuickTime video";

	if (!strcmp(dot, ".zip"))     return "ZIP archive";
	if (!strcmp(dot, ".7z"))      return "7-Zip archive";
	if (!strcmp(dot, ".rar"))     return "RAR archive";
	if (!strcmp(dot, ".tar"))     return "TAR archive";
	if (!strcmp(dot, ".gz"))      return "Gzip compressed file";
	if (!strcmp(dot, ".xz"))      return "XZ compressed file";
	if (!strcmp(dot, ".zst"))     return "Zstandard compressed file";

	if (!strcmp(dot, ".pdf"))     return "PDF document";
	if (!strcmp(dot, ".docx"))    return "Word document";
	if (!strcmp(dot, ".xlsx"))    return "Excel spreadsheet";
	if (!strcmp(dot, ".pptx"))    return "PowerPoint presentation";
	if (!strcmp(dot, ".odt"))     return "OpenDocument text document";
	if (!strcmp(dot, ".ods"))     return "OpenDocument spreadsheet";
	if (!strcmp(dot, ".odp"))     return "OpenDocument presentation";

	if (!strcmp(dot, ".iso"))     return "ISO disk image";
	if (!strcmp(dot, ".img"))     return "disk image";
	if (!strcmp(dot, ".vhdx"))    return "virtual hard disk";
	if (!strcmp(dot, ".vmdk"))    return "VMware virtual disk";
	if (!strcmp(dot, ".vdi"))     return "VirtualBox disk image";
	if (!strcmp(dot, ".qcow2"))   return "QEMU virtual disk";

	if (!strcmp(dot, ".deb"))     return "Debian package";
	if (!strcmp(dot, ".rpm"))     return "RPM package";
	if (!strcmp(dot, ".appimage")) return "AppImage executable";
	if (!strcmp(dot, ".exe"))     return "Windows executable";
	if (!strcmp(dot, ".msi"))     return "Windows installer";
	if (!strcmp(dot, ".dll"))     return "Windows dynamic library";
	if (!strcmp(dot, ".so"))      return "Linux shared library";

	if (!strcmp(dot, ".ttf"))     return "TrueType font";
	if (!strcmp(dot, ".otf"))     return "OpenType font";
	if (!strcmp(dot, ".woff"))    return "Web font";
	if (!strcmp(dot, ".woff2"))   return "Web font";
	return "unknown/directory/empty";
}




int main(int argc,char *argv[]) {
	//if no file/dir entered helper
	if (argc < 2) {
		fprintf(stderr, "Usage: %s <file>\n", argv[0]);
		return 1;
	}
	//multi-word filenames
	char filename[1024] = "";
	//also multi-word filenames
	for (int i = 1; i < argc; i++) {
		if (i > 1)
			strcat(filename, " ");

		strcat(filename, argv[i]);
	}


	struct stat st;
	//error handling
	if(stat(filename, &st) != 0) {
		fprintf(stderr, "pak you %s\n",filename);
		return 1;
	}
	//print file type
	printf("Content:  %s\n", kind(argv[1]));

	//Format & execution
	execlp("stat", "stat","--printf",
		   "File:     %n\n"
		   "Type:     %F\n"
		   "Size:     %s bytes\n"
		   "Perms:    %A (%a)\n"
		   "Owner:    %U:%G\n"
		   "Modified: %y\n",
		"--", filename, (char *)NULL);







	//returns 0
	return 0;
}
