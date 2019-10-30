/*PRIMEIRO ALIEN*/
 #define ET11 "/*-*\\"
 #define ET12 "|/O\\|"
 #define ET13 "\\/-\\/"
 #define ET112 "/*-*\\"
 #define ET122 "_/O\\_"
 #define ET132 "\\/|\\/"
 
 /*SEGUNDO ALIEN*/
 #define ET21 "|O.O|"
 #define ET22 ")_O_("
 #define ET23 "V*+*V"
 #define ET212 "/o.o\\"
 #define ET222 "/|_|\\"
 #define ET223 "(_O_)"
 
 /*TERCEIRO ALIEN*/
 #define ET31 "/-.-\\" 
 #define ET32 "()O()"
 #define ET33 "\\/!\\/"
 #define ET312 "|¬.¬|"
 #define ET322 "*)o(*"

struct aliens {
        int status; /*vivo ou morto*/
	int versao; /*para saber se eu printo a primeira ou a segunda versao*/
        char corpo1[6];
 	char corpo2[6];
        char corpo3[6];
 };
 typedef struct aliens t_aliens;


