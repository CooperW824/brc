
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <byteswap.h>

typedef uint32_t uint32;

char data[][100] = {
		"Abha",
		"Abidjan",
		"Abéché",
		"Accra",
		"Addis Ababa",
		"Adelaide",
		"Aden",
		"Ahvaz",
		"Albuquerque",
		"Alexandra",
		"Alexandria",
		"Algiers",
		"Alice Springs",
		"Almaty",
		"Amsterdam",
		"Anadyr",
		"Anchorage",
		"Andorra la Vella",
		"Ankara",
		"Antananarivo",
		"Antsiranana",
		"Arkhangelsk",
		"Ashgabat",
		"Asmara",
		"Assab",
		"Astana",
		"Athens",
		"Atlanta",
		"Auckland",
		"Austin",
		"Baghdad",
		"Baguio",
		"Baku",
		"Baltimore",
		"Bamako",
		"Bangkok",
		"Bangui",
		"Banjul",
		"Barcelona",
		"Bata",
		"Batumi",
		"Beijing",
		"Beirut",
		"Belgrade",
		"Belize City",
		"Benghazi",
		"Bergen",
		"Berlin",
		"Bilbao",
		"Birao",
		"Bishkek",
		"Bissau",
		"Blantyre",
		"Bloemfontein",
		"Boise",
		"Bordeaux",
		"Bosaso",
		"Boston",
		"Bouaké",
		"Bratislava",
		"Brazzaville",
		"Bridgetown",
		"Brisbane",
		"Brussels",
		"Bucharest",
		"Budapest",
		"Bujumbura",
		"Bulawayo",
		"Burnie",
		"Busan",
		"Cabo San Lucas",
		"Cairns",
		"Cairo",
		"Calgary",
		"Canberra",
		"Cape Town",
		"Changsha",
		"Charlotte",
		"Chiang Mai",
		"Chicago",
		"Chihuahua",
		"Chișinău",
		"Chittagong",
		"Chongqing",
		"Christchurch",
		"City of San Marino",
		"Colombo",
		"Columbus",
		"Conakry",
		"Copenhagen",
		"Cotonou",
		"Cracow",
		"Da Lat",
		"Da Nang",
		"Dakar",
		"Dallas",
		"Damascus",
		"Dampier",
		"Dar es Salaam",
		"Darwin",
		"Denpasar",
		"Denver",
		"Detroit",
		"Dhaka",
		"Dikson",
		"Dili",
		"Djibouti",
		"Dodoma",
		"Dolisie",
		"Douala",
		"Dubai",
		"Dublin",
		"Dunedin",
		"Durban",
		"Dushanbe",
		"Edinburgh",
		"Edmonton",
		"El Paso",
		"Entebbe",
		"Erbil",
		"Erzurum",
		"Fairbanks",
		"Fianarantsoa",
		"Flores,  Petén",
		"Frankfurt",
		"Fresno",
		"Fukuoka",
		"Gabès",
		"Gaborone",
		"Gagnoa",
		"Gangtok",
		"Garissa",
		"Garoua",
		"George Town",
		"Ghanzi",
		"Gjoa Haven",
		"Guadalajara",
		"Guangzhou",
		"Guatemala City",
		"Halifax",
		"Hamburg",
		"Hamilton",
		"Hanga Roa",
		"Hanoi",
		"Harare",
		"Harbin",
		"Hargeisa",
		"Hat Yai",
		"Havana",
		"Helsinki",
		"Heraklion",
		"Hiroshima",
		"Ho Chi Minh City",
		"Hobart",
		"Hong Kong",
		"Honiara",
		"Honolulu",
		"Houston",
		"Ifrane",
		"Indianapolis",
		"Iqaluit",
		"Irkutsk",
		"Istanbul",
		"İzmir",
		"Jacksonville",
		"Jakarta",
		"Jayapura",
		"Jerusalem",
		"Johannesburg",
		"Jos",
		"Juba",
		"Kabul",
		"Kampala",
		"Kandi",
		"Kankan",
		"Kano",
		"Kansas City",
		"Karachi",
		"Karonga",
		"Kathmandu",
		"Khartoum",
		"Kingston",
		"Kinshasa",
		"Kolkata",
		"Kuala Lumpur",
		"Kumasi",
		"Kunming",
		"Kuopio",
		"Kuwait City",
		"Kyiv",
		"Kyoto",
		"La Ceiba",
		"La Paz",
		"Lagos",
		"Lahore",
		"Lake Havasu City",
		"Lake Tekapo",
		"Las Palmas de Gran Canaria",
		"Las Vegas",
		"Launceston",
		"Lhasa",
		"Libreville",
		"Lisbon",
		"Livingstone",
		"Ljubljana",
		"Lodwar",
		"Lomé",
		"London",
		"Los Angeles",
		"Louisville",
		"Luanda",
		"Lubumbashi",
		"Lusaka",
		"Luxembourg City",
		"Lviv",
		"Lyon",
		"Madrid",
		"Mahajanga",
		"Makassar",
		"Makurdi",
		"Malabo",
		"Malé",
		"Managua",
		"Manama",
		"Mandalay",
		"Mango",
		"Manila",
		"Maputo",
		"Marrakesh",
		"Marseille",
		"Maun",
		"Medan",
		"Mek'ele",
		"Melbourne",
		"Memphis",
		"Mexicali",
		"Mexico City",
		"Miami",
		"Milan",
		"Milwaukee",
		"Minneapolis",
		"Minsk",
		"Mogadishu",
		"Mombasa",
		"Monaco",
		"Moncton",
		"Monterrey",
		"Montreal",
		"Moscow",
		"Mumbai",
		"Murmansk",
		"Muscat",
		"Mzuzu",
		"N'Djamena",
		"Naha",
		"Nairobi",
		"Nakhon Ratchasima",
		"Napier",
		"Napoli",
		"Nashville",
		"Nassau",
		"Ndola",
		"New Delhi",
		"New Orleans",
		"New York City",
		"Ngaoundéré",
		"Niamey",
		"Nicosia",
		"Niigata",
		"Nouadhibou",
		"Nouakchott",
		"Novosibirsk",
		"Nuuk",
		"Odesa",
		"Odienné",
		"Oklahoma City",
		"Omaha",
		"Oranjestad",
		"Oslo",
		"Ottawa",
		"Ouagadougou",
		"Ouahigouya",
		"Ouarzazate",
		"Oulu",
		"Palembang",
		"Palermo",
		"Palm Springs",
		"Palmerston North",
		"Panama City",
		"Parakou",
		"Paris",
		"Perth",
		"Petropavlovsk-Kamchatsky",
		"Philadelphia",
		"Phnom Penh",
		"Phoenix",
		"Pittsburgh",
		"Podgorica",
		"Pointe-Noire",
		"Pontianak",
		"Port Moresby",
		"Port Sudan",
		"Port Vila",
		"Port-Gentil",
		"Portland OR}",
		"Porto",
		"Prague",
		"Praia",
		"Pretoria",
		"Pyongyang",
		"Rabat",
		"Rangpur",
		"Reggane",
		"Reykjavík",
		"Riga",
		"Riyadh",
		"Rome",
		"Roseau",
		"Rostov-on-Don",
		"Sacramento",
		"Saint Petersburg",
		"Saint-Pierre",
		"Salt Lake City",
		"San Antonio",
		"San Diego",
		"San Francisco",
		"San Jose",
		"San José",
		"San Juan",
		"San Salvador",
		"Sana'a",
		"Santo Domingo",
		"Sapporo",
		"Sarajevo",
		"Saskatoon",
		"Seattle",
		"Ségou",
		"Seoul",
		"Seville",
		"Shanghai",
		"Singapore",
		"Skopje",
		"Sochi",
		"Sofia",
		"Sokoto",
		"Split",
		"St. John's",
		"St. Louis",
		"Stockholm",
		"Surabaya",
		"Suva",
		"Suwałki",
		"Sydney",
		"Tabora",
		"Tabriz",
		"Taipei",
		"Tallinn",
		"Tamale",
		"Tamanrasset",
		"Tampa",
		"Tashkent",
		"Tauranga",
		"Tbilisi",
		"Tegucigalpa",
		"Tehran",
		"Tel Aviv",
		"Thessaloniki",
		"Thiès",
		"Tijuana",
		"Timbuktu",
		"Tirana",
		"Toamasina",
		"Tokyo",
		"Toliara",
		"Toluca",
		"Toronto",
		"Tripoli",
		"Tromsø",
		"Tucson",
		"Tunis",
		"Ulaanbaatar",
		"Upington",
		"Ürümqi",
		"Vaduz",
		"Valencia",
		"Valletta",
		"Vancouver",
		"Veracruz",
		"Vienna",
		"Vientiane",
		"Villahermosa",
		"Vilnius",
		"Virginia Beach",
		"Vladivostok",
		"Warsaw",
		"Washington, D.C.",
		"Wau",
		"Wellington",
		"Whitehorse",
		"Wichita",
		"Willemstad",
		"Winnipeg",
		"Wrocław",
		"Xi'an",
		"Yakutsk",
		"Yangon",
		"Yaoundé",
		"Yellowknife",
		"Yerevan",
		"Yinchuan",
		"Zagreb",
		"Zanzibar City",
		"Zürich",
};


#include <stdint.h> /* Replace with <stdint.h> if appropriate */
#define get16bits(d) ((((uint32_t)(((const uint8_t *)(d))[1])) << 8)\
                       +(uint32_t)(((const uint8_t *)(d))[0]) )

uint32_t SuperFastHash (const char * data, int len) {
uint32_t hash = len, tmp;
int rem;

    if (len <= 0 || data == NULL) return 0;

    rem = len & 3;
    len >>= 2;

    /* Main loop */
    for (;len > 0; len--) {
        hash  += get16bits (data);
        tmp    = (get16bits (data+2) << 11) ^ hash;
        hash   = (hash << 16) ^ tmp;
        data  += 2*sizeof (uint16_t);
        hash  += hash >> 11;
    }

    /* Handle end cases */
    switch (rem) {
        case 3: hash += get16bits (data);
                hash ^= hash << 16;
                hash ^= ((signed char)data[sizeof (uint16_t)]) << 18;
                hash += hash >> 11;
                break;
        case 2: hash += get16bits (data);
                hash ^= hash << 11;
                hash += hash >> 17;
                break;
        case 1: hash += (signed char)*data;
                hash ^= hash << 10;
                hash += hash >> 1;
    }

    /* Force "avalanching" of final 127 bits */
    hash ^= hash << 3;
    hash += hash >> 5;
    hash ^= hash << 4;
    hash += hash >> 17;
    hash ^= hash << 25;
    hash += hash >> 6;

    return hash;
}

int hash(char *str)
{
	return SuperFastHash(str, strlen(str));
}

int main()
{
	int collisions = 0;
	int TABLE_SIZE = 500;

	do
	{
		collisions = 0;
		int occurrences[TABLE_SIZE];

		for (int i = 0; i < TABLE_SIZE; i++)
		{
			occurrences[i] = 0;
		}

		for (int i = 0; i < 413; i++)
		{
			int hashRes = hash(data[i]) % TABLE_SIZE;
			occurrences[hashRes] = occurrences[hashRes] + 1;
		}

		for (int i = 0; i < TABLE_SIZE; i++)
		{
			if (occurrences[i] > 1)
				collisions++;
		}

		TABLE_SIZE++;
	} while (collisions);

	std::cout << TABLE_SIZE << " Min Table Size for 0 Collisions " << std::endl;
}