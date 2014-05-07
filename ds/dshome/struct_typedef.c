typedef struct address_s
{
char *street;
char *city;
char *region;
char *country;
char *postal_code;
} ADDRESS_t, *ADDRESS_p_t;
static void print_address(
ADDRESS_p_t address_info
);
static void print_an_address( void )
{
ADDRESS_t address;
address.street = “1823 23rd Ave NE”;
address.city = “Seattle”;
address.region = “WA”;
address.postal_code = “98023”;
print_address( &address );
}

