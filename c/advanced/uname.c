#include <stdio.h>
#include <sys/utsname.h>
#define BUF_SIZE 30
int main(void){
/*
struct utsname {
    char sysname[BUF_SIZE];    // Operating system name (e.g., "Linux") 
    char nodename[BUF_SIZE];   // Name within "some implementation-defined network" 
    char release[BUF_SIZE];    // OS release (e.g., "2.6.28") /
    char version[BUF_SIZE];    // OS version /
    char machine[BUF_SIZE];    // Hardware identifier /
    #ifdef _GNU_SOURCE
        char domainname[BUF_SIZE]; //NIS or YP domain name 
    #endif
} buf;
*/
/*
// Structure describing the system and machine.  /
struct utsname
  {
    // Name of the implementation of the operating system.  /
    char sysname[_UTSNAME_SYSNAME_LENGTH];

    // Name of this node on the network.  /
    char nodename[_UTSNAME_NODENAME_LENGTH];

    // Current release level of this implementation.  /
    char release[_UTSNAME_RELEASE_LENGTH];
    // Current version level of this release.  /
    char version[_UTSNAME_VERSION_LENGTH];

    // Name of the hardware type the system is running on.  /
    char machine[_UTSNAME_MACHINE_LENGTH];

#if _UTSNAME_DOMAIN_LENGTH - 0
    // Name of the domain of this node on the network.  /
# ifdef __USE_GNU
    char domainname[_UTSNAME_DOMAIN_LENGTH];
# else
    char __domainname[_UTSNAME_DOMAIN_LENGTH];
# endif
#endif
  } buf ;
*/
struct utsname buf;
uname(&buf);

printf(",buf.sysname);%s",buf.sysname);
printf("buf.nodename);%s",buf.nodename);
printf(",buf.release);%s",buf.release);
printf(",buf.version);%s",buf.version);
printf(",buf.machine);%s",buf.machine);
}
