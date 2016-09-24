#include "readelf.h"
#define MAXBUFSIZE 1000
/* magic number in little endian */
static unsigned char magic_number[] = {0x7f,0x45,0x4c,0x46};

Elf64_Ehdr elf64_header;
Elf32_Ehdr elf32_header;

Elf32_Shdr *elf32_sheaders;
Elf64_Shdr *elf64_sheaders;


static int is_32bit_elf;
static int is_little_endian;
static char string_table[MAXBUFSIZE];
static unsigned int string_table_size = 0;

void die(char * msg)
{
    printf("%s\n",msg);
    exit(1);
}

static
void
get_elf_class (unsigned int elf_class, char *buf)
{
    switch (elf_class)
    {
    case ELFCLASSNONE:
        strcpy(buf,"none");
        break;
    case ELFCLASS32:
        is_32bit_elf = 1;
        strcpy(buf,"ELF32");
        break;
    case ELFCLASS64:
        is_32bit_elf = 0;
        strcpy(buf,"ELF64");
        break;
    default:
        strcpy(buf,"unknown");
    }
    return;
}

static
void
get_elf_data (unsigned int elf_data, char *buf)
{
    switch(elf_data){
    case ELFDATA2LSB:
        is_little_endian = 1;
        strcpy(buf, "little endian");
        break;
    case ELFDATA2MSB:
        is_little_endian = 0;
        strcpy(buf, "big endian");
        break;
    default:
        strcpy(buf, "unknown");
    }
    return;
}

static
void
get_elf_osabi(unsigned int elf_osabi, char *buf)
{
    switch (elf_osabi)
    {
    case ELFOSABI_LINUX:
        strcpy(buf, "Linux");
        break;
    default:
        strcpy(buf, "System V");
    }
    return;
}

static
void
get_elf_type(unsigned int elf_type, char *buf)
{
    switch (elf_type)
    {
    case ET_NONE:
        strcpy(buf, "None");
        break;
    case ET_REL:
        strcpy(buf, "REL (Relocatable file)");
        break;
    case ET_EXEC:
        strcpy(buf, "EXEC (Executable file)");
        break;
    case ET_CORE:
        strcpy(buf, "CORE (Core file)");
        break;
    default:
        strcpy(buf, "unknow");
    }
    return;
}

static
void
get_elf_machine_name (unsigned int e_machine, char *buf)
{
    switch (e_machine)
    {
    case EM_NONE:
        strcpy(buf, "None");
        break;
    case EM_386:
        strcpy(buf, "Intel 80386");
        break;
    case EM_486:
        strcpy(buf, "Intel 80486");
        break;
    case EM_860:
        strcpy(buf, "Intel 80860");
        break;
    case EM_IA_64:
        strcpy(buf, "Intel IA-64");
        break;
    case EM_X86_64:
        strcpy(buf, "Advanced Micro Devices X86-64");
        break;
    default:
        strcpy(buf, "unknown");
    }
    return;
}


static
void read_header(FILE *elf_file)
{
    char buf[MAXBUFSIZE];
    int i;

    unsigned char e_ident[EI_NIDENT];

    int elf_fd;
    if ((elf_fd = fileno(elf_file)) == -1){
        die("fileno error");
    }
    
    
        
    if (fread (e_ident, EI_NIDENT, 1, elf_file) !=1)
        die("fread error");
    rewind(elf_file);

    if (memcmp(magic_number, e_ident, 4) != 0){
        die("not a elf file");
    }
    printf ("ELF Header:\n");
    printf ("  Magic:   ");
    for (i = 0;i < EI_NIDENT;i++){
        printf("%2.2x ", e_ident[i]);
    }
    printf("\n");
    get_elf_class (e_ident[EI_CLASS], buf);
    printf ("  Class: %s\n", buf);
    get_elf_data (e_ident[EI_DATA],buf);
    printf ("  Data: %s\n", buf);
    get_elf_osabi (e_ident[EI_OSABI], buf);
    printf ("  OS/ABI: %s\n", buf);
    

    if (is_32bit_elf){
        if (fread (&elf32_header, sizeof(Elf32_Ehdr), 1, elf_file) !=1){
            die("fread error");
        }
        get_elf_type(elf32_header.e_type, buf);
        printf("  Type: %s\n", buf);
        get_elf_machine_name(elf32_header.e_machine, buf);
        printf("  Machine: %s\n", buf);
        printf("  Entry point address: 0x%x\n", elf32_header.e_entry);
        printf("  Start of program headers: 0x%x\n", elf32_header.e_phoff);
        printf("  Start of section headers: 0x%x\n", elf32_header.e_shoff);
        printf("  Size of this header: 0x%x\n", elf32_header.e_ehsize);
        printf("  Size of program headers: 0x%x\n", elf32_header.e_phentsize);
        printf("  Number of program headers: 0x%x\n", elf32_header.e_phnum);
        printf("  Size of section headers: 0x%x\n", elf32_header.e_shentsize);
        printf("  Number of section headers: 0x%x\n", elf32_header.e_shnum);
        printf("  Section header string table index: 0x%x\n", elf32_header.e_shstrndx);
        printf(" \n");
    } else {
        if (fread (&elf64_header, sizeof(Elf64_Ehdr), 1, elf_file) !=1) {
            die("fread error");
        }
        get_elf_type(elf64_header.e_type, buf);
        printf("  Type: %s\n", buf);
        get_elf_machine_name(elf64_header.e_machine, buf);
        printf("  Machine: %s\n", buf);
        printf("  Entry point address: 0x%llx\n", elf64_header.e_entry);
        printf("  Start of program headers: 0x%llx\n", elf64_header.e_phoff);
        printf("  Start of section headers: 0x%llx\n", elf64_header.e_shoff);
        printf("  Size of this header: %u (bytes)\n", elf64_header.e_ehsize);
        printf("  Size of program headers: %u (bytes)\n", elf64_header.e_phentsize);
        printf("  Number of program headers: %u\n", elf64_header.e_phnum);
        printf("  Size of section headers: %u (bytes)\n", elf64_header.e_shentsize);
        printf("  Number of section headers: %u\n", elf64_header.e_shnum);
        printf("  Section header string table index: %u\n", elf64_header.e_shstrndx);
        printf(" \n");
    }
    return;
}

static
void read_sections(FILE *elf_file)
{
    int i;
    if(is_32bit_elf){
        elf32_sheaders = (Elf32_Shdr *) malloc(sizeof(Elf32_Shdr)*elf32_header.e_shnum);
        /* jump to section headers entry */
        if (fseek(elf_file, elf32_header.e_shoff, SEEK_SET) == -1){
            die("lseek error");
        }
        /* load all setction headers */
        if (fread (elf32_sheaders,
                   sizeof(Elf32_Ehdr),
                   elf32_header.e_shnum,
                   elf_file) != elf32_header.e_shnum){
            die("elf32_sheader fread error");
        }
        
        for (i = 0;i < elf32_header.e_shnum; i++){
            /* read sting table section */
            if (elf32_header.e_shstrndx == i){
                if (fseek(elf_file,
                          elf32_sheaders[i].sh_addr + elf32_sheaders[i].sh_offset,
                          SEEK_SET) == -1){
                    die("lseek error");
                }
                /* load string table */
                if (fread(string_table,
                          elf32_sheaders[i].sh_size,
                          1,
                          elf_file) != 1){
                    die("fread error");
                }
            }/* end if */
        }/* end for */

        /* read each section */
        char *p_stringt = string_table;
        printf("Section headers:\n");
        for (i=0; i < elf32_header.e_shnum; i++){
            printf("index : %d \t name: %s \t addr 0x%x \t offset 0x%x \t size 0x%x\n",
                   i,
                   p_stringt + elf32_sheaders[i].sh_name,
                   elf32_sheaders[i].sh_addr,
                   elf32_sheaders[i].sh_offset);
        }/* end for */
        free(elf32_sheaders);
    } else {
        elf64_sheaders = (Elf64_Shdr *) malloc(sizeof(Elf64_Shdr)*elf64_header.e_shnum);
        /* jump to section headers entry */
        if (fseek(elf_file, elf64_header.e_shoff, SEEK_SET) == -1){
            die("lseek error");
        }
        /* load all setction headers */
        if (fread (elf64_sheaders,
                   sizeof(Elf64_Ehdr),
                   elf64_header.e_shnum,
                   elf_file) != elf64_header.e_shnum){
            die("elf64_sheader fread error");
        }
        
        for (i = 0;i < elf64_header.e_shnum; i++){
            /* read sting table section */
            if (elf64_header.e_shstrndx == i){
                if (fseek(elf_file,
                          elf64_sheaders[i].sh_addr + elf64_sheaders[i].sh_offset,
                          SEEK_SET) == -1){
                    die("lseek error");
                }
                string_table_size = elf64_sheaders[i].sh_size;
                /* load string table */
                if (fread(string_table,
                          elf64_sheaders[i].sh_size,
                          1,
                          elf_file) != 1){
                    die("fread error");
                }
                break;
            }/* end if */
        }/* end for */
        
        unsigned int symtab_shndx = 0; /* symtab section index*/
        unsigned int strtab_shndx = 0;
        char * dynamic_strings;
        unsigned long dynamic_strings_length = 0;
        /* read each section */
        char *p_stringt = string_table;
        printf("Section headers:\n");
        for (i=0; i < elf64_header.e_shnum; i++){
            printf("index : %d \t name: %s \t addr 0x%x \t offset 0x%x  \t size %d\n",
                   i,
                   p_stringt + elf64_sheaders[i].sh_name,
                   elf64_sheaders[i].sh_addr,
                   elf64_sheaders[i].sh_offset,
                   elf64_sheaders[i].sh_size);
            if (elf64_sheaders[i].sh_type == SHT_SYMTAB) {
                symtab_shndx = i;
                #ifdef DEBUG
                printf("find symtab at index %d\n", i);
                #endif
            } else if (elf64_sheaders[i].sh_type == SHT_STRTAB) {
                strtab_shndx = i;
            }
            
        }/* end for */
        printf("\n");
        /* read strtab dynamic_strings */
        if (strtab_shndx) {
            Elf64_Shdr *strtab_shdr = &elf64_sheaders[strtab_shndx];
            dynamic_strings_length = strtab_shdr->sh_size;
            dynamic_strings = (char *) malloc(sizeof(char)*dynamic_strings_length);
            if (fseek(elf_file, strtab_shdr->sh_offset, SEEK_SET) == -1){
                free(dynamic_strings);
                die("lseek error");
            }
            /* load all setction headers */
            if (fread (dynamic_strings,
                       sizeof(char),
                       dynamic_strings_length,
                       elf_file) != dynamic_strings_length){
                free(dynamic_strings);
                die("symtab fread error");
            }
            
        }
        
        /* read symtab section */
        if (symtab_shndx) {
            Elf64_Shdr *symtab_section = &elf64_sheaders[symtab_shndx];
            unsigned long symnum = symtab_section->sh_size / symtab_section->sh_entsize;
#ifdef DEBUG
            printf("%d %d\n", symtab_section->sh_size, symtab_section->sh_entsize);
            printf("%d\n", symnum);
#endif
            Elf64_Sym *syms = (Elf64_Sym *)malloc(sizeof(Elf64_Sym)*symnum);
            if (fseek(elf_file, symtab_section->sh_offset, SEEK_SET) == -1){
                free(syms);
                die("lseek error");
            }
            /* load all setction headers */
            if (fread (syms,
                       sizeof(Elf64_Sym),
                       symnum,
                       elf_file) != symnum){
                free(syms);
                die("symtab fread error");
            }
            printf("Symbol table '.symtab' contains %lu entries: \n", symnum);
            printf("Num:   Value\t\tSize\tType\tBind\tVis\tNdx\tName\n");
            unsigned long idx;
            for (idx = 0; idx < symnum; idx++){
                printf("%3lu:%016lx%4llu",
                       idx,
                       syms[idx].st_value,
                       syms[idx].st_size);
                
                char buf[100];
                char * pbuf = buf;
                
                unsigned char type = ELF64_ST_TYPE(syms[idx].st_info);
                switch (type) {
                case(STT_NOTYPE):
                    pbuf = "NOTYPE";
                    break;
                case(STT_OBJECT):
                    pbuf = "OBJECT";
                    break;
                case(STT_FUNC):
                    pbuf = "FUNC";
                    break;
                case(STT_FILE):
                    pbuf = "FILE";
                    break;
                case(STT_SECTION):
                    pbuf = "SECTION";
                    break;
                default:
                    pbuf = "UNKNOWN";
                }
                
                printf("%8s", pbuf);
                
                unsigned char bind = ELF64_ST_BIND(syms[idx].st_info);

                switch (bind) {
                case(STB_LOCAL):
                    pbuf = "LOCAL";
                    break;
                case(STB_GLOBAL):
                    pbuf = "GLOBAL";
                    break;
                case(STB_WEAK):
                    pbuf = "WEAK";
                    break;
                default:
                    pbuf = "UNKNOWN";
                }
                
                printf("%8s", pbuf);
                
                unsigned char vis = syms[idx].st_other;
                switch(vis) {
                case(0):
                    pbuf = "DEFAULT";
                    break;
                case(2):
                    pbuf = "HIDDEN";
                    break;
                default:
                    pbuf = "UNKNOWN";
                }
                
                printf("%10s", pbuf);
                unsigned int ndx= syms[idx].st_shndx;
                //printf("%lx\t", ndx);
                switch(ndx) {
                case(SHN_ABS):
                    pbuf = "ABS";
                    printf("%6s\t", pbuf);
                    break;
                case(SHN_COMMON):
                    pbuf = "COMMON";
                    printf("%6s\t", pbuf);
                    break;
                case(SHN_UNDEF):
                    pbuf = "UND";
                    printf("%6s\t", pbuf);
                    break;
                default:
                    printf("%6d\t", ndx);
                }                
                
                if (syms[idx].st_name < dynamic_strings_length) {
                    pbuf = dynamic_strings + syms[idx].st_name;
                } else {
                    pbuf = "UNKNOWN";
                }
                printf("%s\n", pbuf);
                
                
            }
            free(dynamic_strings);
            free(syms);
        }
        free(elf64_sheaders);
    }
}



int main(int argc, char** argv)
{
    
    FILE * elf_file = fopen(argv[1],"r");
    read_header(elf_file);
    read_sections(elf_file);
    return 0;
}

