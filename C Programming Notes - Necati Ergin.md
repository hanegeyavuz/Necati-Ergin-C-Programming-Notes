
--- 
# 18.07.2024

## C Dili Özellikleri
- Imperative        
- Procedural
- Non-Proprietary
- Middle-level
- Static Typing 
- General Purpose
- Efficient
- Artificial
- Standard
- Portable
- Expressive


## Kavramlar

- Syntax -> Dilin kuralları
- Semantics -> Dilin anlam kuralla
## Tarihçesi

- Geçmişten günümüze programlama dilleri

![[Pasted image 20240803170410.png]]


## Bir C Programlama Kodunun Aşamaları

- Yazılan C kodları bir file'da tutuluyor. Bu file'lar 1 ve 0 lardan oluşan text dosyalarıdır. Bu **text file**'ların oluşumu için **text editor**leri bulunmakta. 
- C kurallarına göre oluşturulmuş kaynak dosyalarının uzantısı `.c` dir.

### Compiler

- C kaynak kodunu ilgili sistem için assembly veya makine koduna dönüştürür.
- Derleme süreci -> Compiler Time
- **Compiler** çıktısı object file çıktısı oluşturur. (object code)
- **Linker** ise derleyiciden çıkan dosyayı çalıştırılabilir dosya haline getirir. (executable code)

**Neden Linker'a ihtiyacımız var?
- Compiler her source file için ayrı bir çıktı oluşturur.
- Linker ise bu çıktıları alıp birleştirerek çalıştırılabilir bir dosya çıktısı oluşturur.
  
### IDE
- Geliştirme ortamı sunar.
- Optimizasyon imkanı sağlar.
--- 
# 19.07.2024

## Preprocessor

- Kaynak kodda compiler öncesinde kodu işleyen ve bazı işlevleri yerine getiren yapı.
- **`#`** işareti ile yazılan kodlar ön işlemciye verilen komutlardır.
- Girişi ve çıktısı text dosyasıdır.
- Input: Source File
- Output: Translation Unit 

## Debugger

- Yazılan programdaki hataları ayıklayabilen, programı ayrı bir ortamda çalıştırıp bug'ları yakalayabilen yapı.


## Tokenizing

- Token: Derleyici derleme esnasında kodu en küçük parçalara ayırır. Bu parçalara **token** denir.
	- Keyword
	- Identifier (name)
	- Operator
	- Constant
	- String Literal
- Token'lar arasındaki boşluklar kodun anlamını değiştirmez.

## Statement
- Türkçeye deyim olarak geçirilebilir.
- C dilinin cümleleridir.
- Genellikle sonu noktalı virgül, iki nokta gibi ifadelerle biten yapılardır.
- null statement, if statement etc..

- `return = 1;`, `a = 5;` gibi ifadeler  expression statement olarak değerlendirilir.
## Expression

- İfadelerin operatörlerle bir araya gelerek oluşturdukları yapıdır.
- Expressions can be assigned or used as operands, while statements can only be declared.
	- `y = x + 4` bir expression iken,
	- `y = x + 4`; bir statement olmaktadır.

- Her ifade:
	- Bir değere sahiptir.
	- Türe (data type) sahiptir.
	- Bellekte yer kaplar.
	- L value veya R value olmak zorundadır.
		- Bir ifadenin L value olması, bellekte bir nesneye karşılık gelmesi demektir. Bellekte bir yeri temsil eder.
			- `x;`
			- `x = x + 25`;
			- ...
		- R value ise hesaplanacak bir değere karşılık gelir. Bellekte bir yer kaplamaz.
			- `25`
			- `x + 25`
			- ...
>[!NOTE]
> Bir ifade eğer L value ise başına adress operatörü `(&)` getirildiğinde bir syntax hatası oluşmaz. Eğer R value ise hata meydana gelir.
		
--- 
# 23.07.2024

## Sayı Sistemleri

- ### Decimal System


- ### Octal System


- ### Hexadecimal System
	- 0,1,2,3,4,5,6,7,8,9,A,B,C,D,E,F digitlerinden oluşmaktadır.
	- A = 11 , B = 12 , C = 13 , D = 14, E = 15, F = 16
	- İki byte'lık en büyük işaretli sayı: 0x7FFF
	- İki byte'lık en küçük işaretli sayı: 0x8000
	- İki byte'lık alanda -1 değeri : 0xFFFF


- ### Binary System
	- Unsigned Binary System
	- Signed Binary System
	- Her bir birime `bit` (binary digit) denir.
	- `1 byte = 8 bit` eşitliği söz konusudur.
	-  `Word =  2 byte` 
	-  `Double Word (dword) = 4 byte`
	- 010100101 örnek verilebilir.
		- En Sağdaki bite `Least Significant Digit (LSD)`, en soldaki bite ise `Most Significant Digit (MSD)` denir.
	- one's complement (bire tümleme)
		- Bir binary sayının 0 bitleri yerine 1, 1 bitleri yerine 0 koyularak 1 e tümlenir.
		- 00000000 -> 11111111
	- two's complement (ikiye tümleme)
		- Bir binary sayının önce bire tümleyeni alınıp daha sonrasında 1 ile toplanılarak elde edilir. 
		- Pratik yol olarak LSB'den başlayarak 1 biti görene kadar değişiklik yapmayıp, sonrasında solunda kalan bitleri toggle ederek 2 ye tümleyeni alınır.
		- **Sistemlerin büyük çoğunluğunda işaretli 2'lik sayı sisteminde ikiye tümleyen aritmetiği kullanılır.**
		- **En yüksek dereceli bit (işaretli sistemlerde sign bit olarak isimlendirilir) 0 ise sayı pozitif, 1 ise negatiftir.**
		-  10010001 -> Negatif
		-  01001010 -> Pozitif
		- İşaretli değerlerde pozitif bir sayının değeri hesaplanırken işaretsiz değerler gibi hesaplanır. Negatif değerlerin ise yani sign bit i 1 olan sayıların ise 2 ye tümleyeni alınır ve bulunan sonucun negatif değeri bize sonucu verir.

## Karakterlerin Terminolojisi

| Simge | Açıklama         |
| ----- | ---------------- |
| `(`   | Parentheses      |
| `)`   | Parentheses      |
| `[`   | Square Bracket   |
| `]`   | Square Bracket   |
| `{`   | Curly Brace      |
| `}`   | Curly Brace      |
| `<`   | Angular Bracket  |
| `>`   | Angular Bracket  |
| `!`   | Exclamation Mark |
| `"`   | Double Quote     |
| `'`   | Single Quote     |
| `#`   | Number Sign      |
| `&`   | Ampersand        |
| `*`   | Asterisk         |
| `-`   | Hyphen           |
| `.`   | Period           |
| `/`   | Slash            |
| `\`   | Back Slash       |
| `:`   | Colon            |
| `;`   | Semi-colon       |
| `^`   | Caret            |
| `     | `                |
| `~`   | Tilde            |

## C Programlamaya Giriş

```C
#include <stdio.h>   /* Önişlemci Komutu*/
int main() {

    printf("Hello, World!\n"); 

    return 0;

}
```

Out: `Hello, World!` 
- Burada ismi main olan bir fonksiyon tanımlanmış, main fonksiyonu içinde ismi printf olan bir fonksiyon çağrılmıştır.

- Kod tekrarından kaçınmak, test edilebilir halde kod yazabilmek gibi önemli sebepler dolayısıyla **fonksiyonlar** kullanılır.
	- function definition
	- function call
	- function declaration
- *NOT:* `{ }` bu brace'lerin arasında kalan alana **block** denir.

### Data Types

---
- **`char`** types    1 byte
- **char** (derleyiciye bağlı olarak işaretli veya işaretsiz olabilir)
- **signed char**    -128 / 127
- **unsigned char**    0 / 255
---
- **`short`** types    2 byte
- short int
- signed short
- unsigned short
---
- signed **`int `**   2/4/8 byte
- unsigned int
---
- signed long int    4 byte
- unsigned long int
---
- signed long long int    8 byte
- unsigned long long int    
---
- `short` <= `int` <= `long` <= `long long ` **OLMAK ZORUNDA**
- *char* türünün 1 byte olması zorunludur. *long long* türü ise **en az 8 byte** olmak zorundadır. Geri kalan büyüklükler derleyiciye bırakılmış durumdadır.
--- 
# 25.07.2024

- Assignment ve initialize aynı şeyler değildir. Her `=` görülen yere *atama* demek doğru değildir.
- Initialize -> `int a = 5;`
- Assignment -> `a = 5`
---
- Kullanılan derleyicideki data type'ların kaç byte alan kapladığını görmek için aşağıdaki kodu kullanabilirsiniz:
```C
#include <stdio.h>

  

int a;  /*Istenilen tüde değişken tanımı*/

  

int main() {

    printf("%d\n",sizeof(a));

    return 0;

}

```

- Daha sık kullanılan türler:
	- Tam sayı türlerinde `int` , gerçek sayı tülerinde `double`'dır. 
	
---
### Derleyicinin Zorunlu Kıldığı İsimlendirme Kuralları
- `A.....Z` (26)
- `a......z` (26)
- `0......9` (10)
- `_`
- Bu karakterler dışında isimlendirmede bir karakter kullanılmamalı.
- Türkçe karakter kullanılmamalı.
- İsimlendirme herhangi bir rakam ile başlayamaz.
- **C Standardına göre `__` ile veya `_` sonrası büyük harf ile bir isim başlayamaz. Bunlar standarda rezerve edilmiştir.**
- **C programlama büyük - küçük harf duayrlı bir dildir.**
---
### Storage Duration / Lifespan
- Her değişkenin bir ömrü vardır.
	- Static Duration
		- Programın sonuna kadar ömrünü sürdüren değişkenlerdir.
	- Automatic Duration
		- Yalnızca belirli bir kodun yürütülmesi süresince bellekte yer edinen değişkenlerdir.
	- Dynamic Duration
		- Dynamic Memory Allocation ile ömürleri kod içerisindeki komutlarla ayarlanabilen değişkenlerdir.
	
- **Global değişkenler statik ömürlüdür.**
- Local değişkenler başında `static` keyword'ü ile tanımlama yapılmadığı sürece automatic ömürlüdür.

```C
int g;                 /*Global Variable*/

int main(){
	int l;             /*Local Variable*/
}
```

- Static ömürlü değişkenler initialize edilmese bile başlangıç değeri `0` kabul edilir.
- Static yerel değişkenler  initialize edilmese bile başlangıç değeri `0` kabul edilir.
- Automatic ömürlü değişkenler init edilmediği zaman bellekte bulunduğu yerdeki değerini alır. Yani ilk değeri tahmin edilemez. (Örneğin bellekte 0110101 değerine sahipse 53 değerini alır. ) **(Indetermined Value)**
- Static Değişkenlere ilk değer verilirken verilen değer constant olmak zorundadır.
--- 
### Önemli Birkaç Terim!!

- Undefined behaviour 
	- Tanımsız Davranış. 
	- Tanımsız Davranış = Ölüm.
	- Programın runtime aşamasında hiçbir garantisinin olmamasıdır.
		- **Indetermined Value kullanılması undefined behaviour'dır!!!**
		- **Derleyici optimizasyon sürecinde bir tane bile tanımsız davranış olmadığını varsayar.**
		- 
```c
int a = 10;  /*Doğru kullanım.*/
int b = a;   /*Yanlış kullanım. Constant Value olması gerekiyor.*/

int main(){
	int x;            /*Automatic değişken, ilk değeri belirsiz.*/
	int y = x + 5;    /*Undefined behaviour. "x" indetermined Value'dur.*/
}
```

```c
a = x / y; /*Eğer y = 0 ise Undefined behaviour.*/
```

- Unspecified behaviour
	- 
- Implementation Defined

--- 
### Scope
- Scope isimlere(identifier) ilişkin bir kavramdır.
- C ve C++ dillerinde bildirilen her ismin scope denilen bir niteliği vardır.
- Bildirilen bir ismin, nerede kullanılırsa aynı değişkenden bahsedildiğinin anlaşılmasıdır. 
- Compile Time a ilişkin bir kavramdır.
- 4 kategoriye ayrılır.
	- **File Scope**
		- **Bildirilen isimler bildirildikleri yerden itibaren her yerde kullanılabilir.**
		- **Global namespace**'de bildirilen isimlerin scope'u file scope olur. 
	- **Block Scope**
		- `{ }` bu iki brace arasında kalan kısma block denir.
		- Bir isim eğer block içerisinde bildirilirse, o isim bildirildiği noktadan block sonuna kadar (closing brace) tanımlıdır. 
		- 
	- **Function Prototype Scope**
	- **Function Scope**

```c
int main(void){

/* a değişkeni burda kullanılamaz (out of scope)  */
	if(1) {
		/* a değişkeni burda kullanılamaz (out of scope)  */
		int a = 4;
		/* a değişkeni burda kullanılabilir  */
	}
	/* a değişkeni burda kullanılamaz (out of scope)  */

}
```

---
# 26.07.2024

### Name Lookup
- Derleyicinin ismin (identifier) nerede tanımlandığını aramasıdır.
- Scope ile benzerdir fakat aynı şeyler değildir.
- C ve C++ dillerinde isim arama, aranan ismin bulunmasıyla biter ve bir daha başlamaz.
- İsmin aranması aşağıdaki sıraya göre özelden genele yapılır.
- 
```c
/* Bu olaya name hiding de denebilir. */
/* C programlamada iyi bir şey değildir.*/
int a = 5; /*Unvisible*/

int main(void){ /* 3 */

	}           /* 2 */
		int a = 10;     /*Name Lookup burda sona erer.*/
		{       /* 1 */
		
			a = 99;
		
		}
	}
}
```


--- 
# 02.08.2024
## Call By Value

- Fonksiyona değişkenin kendisini göndermiyoruz.
- Fonksiyona değişkenin değerini gönderiyoruz
- Yani çağırdığımız fonksiyon bizim gönderdiğimiz değeri kullanabilir fakat değiştiremez.
```c
int foo(int x){
	x = 655;
}

int main(void){
	int a = 4;
	a = foo(a);      
	printf("%d",a);    /*a = 4 */
}
```

## Call By Reference

- Fonksiyona değişkenin kendisini gönderiyoruz.
- Fonksiyon gönderdiğimiz değeri kullanabilir, değiştirebilir.

```c
int foo(int *x){
	*x = 655;
}

int main(void){
	int a = 4;
	a = foo(&a);      
	printf("%d",a);    /*a = 655 */
}
```

## Constants

- Sabitlerin türleri var. Bir sabiti yazarken hangi türde yazdığımız kodun anlamını **değiştirebilir**t


### Integer Constants

- Decimal -> 1265
- Octal -> **0 ön eki alır** 012
- Hex -> *0x ön eki alır* 0x4A4B

#### Türleri
- int
- uint                                   3456u
- long                                  10l
- unsigned long                  1764ul
- long long                          3678768ll
- unsigned long long          45676543ull

- Son ek yoksa int olur.
- 
### Floating Constants

- Eğer son ek yoksa double olur.
#### Türleri 
- double                       0.6 veya .6
- float                           0.6f
- long double               0.6l, 3.L

>[!NOTE]
>büyük küçük harf farketmiyor


--- 
# 06.08.2024

## Karakter Sabitleri

| 34    | Int                |
| ----- | ------------------ |
| 34U   | Unsigned Int       |
| 34L   | Long               |
| 34UL  | Unsigned Long      |
| 34LL  | Long Long          |
| 34ULL | Unsigned Long Long |

Character Coding:
- Sistemde kaç tane karakter var, bu karakterler neler?
- Her karakterimn bir tam sayı karşılığı var.
- Bix ASCII karakter kodlamasını kullanıyoruz.

- 'A' gibi gösterimlerde karakterin değerini gösteriyoruz.

### Escape Sequence

- '\' ile yazılan karakterlerdir. Burda kurallar dışına çıkılarak farklı anlamlara gelebiliyor.

| Escape Sequence | Name               | Description                                                                            |
| --------------- | ------------------ | -------------------------------------------------------------------------------------- |
| \a              | Alarm or Beep      | It is used to generate a bell sound in the C program.                                  |
| \b              | Backspace          | It is used to move the cursor one place backward.                                      |
| \f              | Form Feed          | It is used to move the cursor to the start of the next logical page.                   |
| \n              | New Line           | It moves the cursor to the start of the next line.                                     |
| \r              | Carriage Return    | It moves the cursor to the start of the current line.                                  |
| \t              | Horizontal Tab     | It inserts some whitespace to the left of the cursor and moves the cursor accordingly. |
| \v              | Vertical Tab       | It is used to insert vertical space.                                                   |
| \\              | Backlash           | Use to insert backslash character.                                                     |
| \’              | Single Quote       | It is used to display a single quotation mark.                                         |
| \”              | Double Quote       | It is used to display double quotation marks.                                          |
| \?              | Question Mark      | It is used to display a question mark.                                                 |
| \ooo            | Octal Number       | It is used to represent an octal number.                                               |
| \xhh            | Hexadecimal Number | It represents the hexadecimal number.                                                  |
| \0              | NULL               | It represents the NULL character.                                                      |
| \e              | Escape sequence    | It represents the ASCII escape character.                                              |
| \s              | Space Character    | It represents the ASCII space character.                                               |
| \d              | Delete Character   | It represents the ASCII DEL character.                                                 |

#### Karakter sabitleri yazım biçimleri:

```c
int x = 'A';     // Standard Format
int y = '\n';    // Specials
int z = '\x1a'   // Hexadecimal
int w = '\054'   // Octal
```


## Input - Output Operation

- Standard Input Stream (klavye)
- Standard Output Input (Monitör)
- Standard Error Stream (Monitör)

**Burdan sonrasına katılamadım. Tekrar edeceğim.**


# 08.08.2024

## printf fonksiyonu

- Variadic bir fonksiyondur
- Yazılar null terminated char türünden tutulur.
- Geri dönüş değeri standart output a yazılan karakter sayısıdır.
- "x" string literal denir. Bir dizidir. (Kursun ilerleyen süreçlerinde daha detaylı anlatılacak.)
- %d gibi ifadeler formatlama için kullanılır. (conversion spesificier)
 - The below table contains the most commonly used format specifiers in C:

| Format Specifier     | Description                                |
| -------------------- | ------------------------------------------ |
| ****%c****           | For character type.                        |
| ****%d****           | For signed integer type.                   |
| ****%e or %E****     | For scientific notation of floats.         |
| ****%f****           | For float type.                            |
| ****%g or %G****     | For float type with the current precision. |
| ****%i****           | signed integer                             |
| ****%ld or %li****   | Long                                       |
| ****%lf****          | Double                                     |
| ****%Lf****          | Long double                                |
| ****%lu****          | Unsigned int or unsigned long              |
| ****%lli or %lld**** | Long long                                  |
| ****%llu****         | Unsigned long long                         |
| ****%o****           | Octal representation                       |
| ****%p****           | Pointer                                    |
| ****%s****           | String                                     |
| ****%u****           | Unsigned int                               |
| ****%x or %X****     | Hexadecimal representation                 |
| ****%n****           | Prints nothing                             |
| ****%%****           | Prints % character                         |

## scanf Fonksiyonu
- Scanf bir formatlı **giriş** fonksiyonudur.
- Variadic bir fonksiyondur.
- Call by reference kullanır.
- Girdi olarak adress girilmesi gerekir.
- Başarı garantisi olmayan bir fonksiyondur. Bu yüzden scanf in geri dönüş değeri başarı bilgisidir.
- Geri dönüş değeri set ettiği değişken sayısıdır.
- Scanf'i mutlaka kontrol etmek gerekir.
- Kullanıcının girişine bağlı olarak istenen set işlemini yapamamış olabilir.
- Scanf başarısız olursa hafızasındaki buffer ı temizlemiyor. 
- Eğer scanf giriş işlemini std.input buffer'ına karakter gelmediği için yani buffer boş bırakıldığı için başarısız olmuşsa, geri dönüş değeri bir hata kodu olarak -1 değeridir.
---
### Operators:
- 45 adet operatör vardır.
- a + b ifadesinde + operator iken, a ve b operand olarak isimlendirilir.
- !x -> prefix
- y++ -> posfix

- binary operator: (2 operand)
- unary operator: (1 operand)
- ternary operator: (3 operand)

- C dilinde her operatörün ürettiği bir değer vardır.
#### Operators Precedense:

| Precedence | Operator       | Description                                       | Associativity                          |            |
| :--------: | -------------- | ------------------------------------------------- | -------------------------------------- | ---------- |
|     1      | `++ --`        | Suffix/postfix increment and decrement            | Left-to-right                          |            |
|            | `()`           | Function call                                     |                                        |            |
|            | `[]`           | Array subscripting                                |                                        |            |
|            | `.`            | Structure and union member access                 |                                        |            |
|            | `->`           | Structure and union member access through pointer |                                        |            |
|            | `(type){list}` | Compound literal (C99)                            |                                        |            |
|     2      | `++ --`        | Prefix increment and decrement[^1]                | Right-to-left                          |            |
|            | `+ -`          | Unary plus and minus                              |                                        |            |
|            | `! ~`          | Logical NOT and bitwise NOT                       |                                        |            |
|            | `(type)`       | Cast                                              |                                        |            |
|            | `*`            | Indirection (dereference)                         |                                        |            |
|            | `&`            | Address-of                                        |                                        |            |
|            | `sizeof`       | Size-of[^2]                                       |                                        |            |
|            | `_Alignof`     | Alignment requirement (C11)                       |                                        |            |
|     3      | `* / %`        | Multiplication, division, and remainder           | Left-to-right                          |            |
|     4      | `+ -`          | Addition and subtraction                          |                                        |            |
|     5      | `<< >>`        | Bitwise left shift and right shift                |                                        |            |
|     6      | `< <=`         | Relational operators `<` and `<=`                 |                                        |            |
|            | `> >=`         | Relational operators `>` and `>=`                 |                                        |            |
|     7      | `== !=`        | Relational operators `==` and `!=`                |                                        |            |
|     8      | `&`            | Bitwise AND                                       |                                        |            |
|     9      | `^`            | Bitwise XOR (exclusive OR)                        |                                        |            |
|     10     | `              | `                                                 | Bitwise OR (inclusive OR)              |            |
|     11     | `&&`           | Logical AND                                       |                                        |            |
|     12     | `              |                                                   | `                                      | Logical OR |
|     13     | `?:`           | Ternary conditional[^3]                           | Right-to-left                          |            |
|   14[^4]   | `=`            | Simple assignment                                 |                                        |            |
|            | `+= -=`        | Assignment by sum and difference                  |                                        |            |
|            | `*= /= %=`     | Assignment by product, quotient, and remainder    |                                        |            |
|            | `<<= >>=`      | Assignment by bitwise left shift and right shift  |                                        |            |
|            | `&= ^=         | =`                                                | Assignment by bitwise AND, XOR, and OR |            |
|     15     | `,`            | Comma                                             | Left-to-right                          |            |

[^1]: Prefix increment and decrement
[^2]: Size-of
[^3]: Ternary conditional
[^4]: Includes assignment operators such as `+=`, `-=`, etc.
# 09.08.2024

## Operators Cont'd

### Aritmetik Operators

- `+` ve `-` operatörleri binary operatorlerdir.
	- R value ifadelerdir (x + y)
	- Temel özelliklerini not almadım. (toplama yapar çıkarma yapar vs vs...)
- `/`, `*` ve `%` operatörlerinin öncelik sıralaması soldan sağadır. R value olarak geçerler.

- `++` ve `--` increment ve decrement operatörlerinin operand'ı L Value **olmak zorundadır.**
- Pre-increment/pre-decrement kullanımı daha yaygındır. (`++a)
- Son ek kullanıldığında ifade bitmeden değer inc-dec yapılmaz.
- Ön ek kullanıldığında ifade bitmeden değer değişir.

```c
int x = 23;
int y = 7;
printf("%d\n", x-- % ++y); // x kendi değerinde kalacak y 1 artacak
printf("+d\n", x % y); // x bir azalarak 22 olur.
```

out:
```
7
6
```


C programlamada, ön ek ve son ek artırma/azaltma operatörleri (`++` ve `--`) genellikle yan etkilere (side effects) neden olur. Bu operatörlerin nasıl çalıştığını ve hangi durumlarda yan etkilere yol açtığını anlamak önemlidir.

### Ön Ek ve Son Ek Operatörleri

1. **Pre-Increment/Decrement (Ön Ek):**
   - `++x` veya `--x` şeklinde yazılır.
   - Önce değişkenin değeri artırılır veya azaltılır, sonra bu yeni değer kullanılır.

   **Örnek:**
   ```c
   int x = 5;
   int y = ++x; // x önce 6 olur, sonra y'ye atanır.
   // Sonuç: x = 6, y = 6
   ```

2. **Post-Increment/Decrement (Son Ek):**
   - `x++` veya `x--` şeklinde yazılır.
   - Önce değişkenin mevcut değeri kullanılır, sonra bu değer artırılır veya azaltılır.

   **Örnek:**
   ```c
   int x = 5;
   int y = x++; // y önce 5 olur, sonra x 6 olur.
   // Sonuç: x = 6, y = 5
   ```

### Side Effect (Yan Etki)

Bu operatörlerin yan etki oluşturmasının nedeni, bir değişkenin değerinin programın durumu içinde değiştirilmesidir. Bu, özellikle karmaşık ifadelerde veya aynı değişkenin birden fazla kez kullanıldığı durumlarda dikkat edilmesi gereken bir durumdur.

**Örnek:**
```c
int x = 5;
int y = x++ + ++x; 
```

Bu örnekte, `x++` ve `++x` operatörlerinin sırası ve yan etkileri önemlidir:

- İlk olarak `x++` ifadesi çalışır, bu durumda `x`'in değeri 5'tir ve bu değer kullanılır, ardından `x` 6 olur.
- Daha sonra `++x` ifadesi çalışır, burada `x` değeri 7'ye yükseltilir ve bu yeni değer kullanılır.
- Sonuç olarak, `y = 5 + 7` olur ve `y` 12 değerini alır, `x` ise 7'dir.

Bu tür ifadelerdeki yan etkiler, özellikle aynı değişkenin birden fazla kez kullanıldığı durumlarda karmaşık ve tahmin edilmesi zor sonuçlara yol açabilir. Bu nedenle, bu tür ifadelerden kaçınmak ya da çok dikkatli kullanmak genellikle iyi bir programlama pratiğidir.

### Genel Öneriler
- Aynı değişkenin birden fazla kez artırıldığı veya azaltıldığı karmaşık ifadelerden kaçının.
- Yan etkilerin daha kolay anlaşılması için, artırma/azaltma işlemlerini basit ve tek başına kullanın.
- Programın tahmin edilebilirliğini artırmak için kodunuzu daha okunabilir ve anlaşılır hale getirin.

### Karşılaştırma Operatorleri

- `>`, `>=`, `<`, `<=`, `==` operatörleridir.
- Geri dönüş değeri **`int`** olur.
--- 
# 13.08.2024 


```c
b = x == y;

---------------------------

if(x == y)
	b = 1;
else
	b = 0;

---------------------------
// Yukarıdaki iki ifade aynı anlamı taşımaktadır.
```

- Ekstra bilgi:
	- double ve float değişkenlerin karşılaştırılması tam sayılar gibi değildir. 
```c
if(dval == 3.4) // Yanlış

if(dval - 3.4 <= 0.000001) // Doğru
```

## Logic Operators

- !expr
- exp1 && expr2
- exp1 || expr2
- expr ? op1 : op2
- if(expr)
- while(expr)
- do ... while(expr)
- for (;expr;)

### ! Operatörü
- Tek operandı vardır.
	- !op1
- **Yan etkisi yoktur.**
```c
if(!a){}
```

### && ve || Operatörleri
- Her iki operant lojik yorumlamaya tabi tutulur.
- **&& yerine & kullanmak kesinlikle hatalıdır ve kodun anlamını değiştirir.**
	- Bu karmaşıklığı engellemek için C++ dilinde && veya || yerine `and`, `or` anahtar sözcüğü kullanılabilir. **C dilinde böyle bir standart alternatif yoktur.**
```c
#include <stdio.h>

int main(void)
{
	int x,y;
	printf("İki tamsayi giriniz: ");
	scanf("%d%d", &x, &y);
    printf("%d && %d = %d \n",x,y,(x && y));
    printf("%d || %d = %d \n",x,y,(x || y));
}
```

- De-Morgan kuralları geçerlidir. 
	- !(a && b) = !a || !b
	- !(a || b) = !a && !b
### Kısa Devre Davranışı (Short Circuit Behaviour)

>[!NOTE]
> Lojik && operatöründe öncelikle sol operand değerlendirilir. Eğer sol operand lojik doğru değilse sağ operand hiç yapılmaz.

>[!NOTE]
> Lojik || operatöründe öncelikle sol operand değerlendirilir. Eğer sol operand lojik doğru ise sağ operand hiç yapılmaz.

```c
#include <stdio.h>

int main(void)
{
	if(x > 10 && y > 20)
		++a;
}
/*YUKARIDAKİ İFADEDE X 10 DAN BÜYÜK DEĞİLSE Y<20 LOJİK İŞLEMİ YAPILMAZ. KISA DEVRE DAVRANIŞI VARDIR.*/

```

```c
#include <stdio.h>

int main(void)
{
	int x = 0;
	int y = 555;
	int z = x && ++y;
    printf("%d\n", z);
    printf("%d\n", y);
}
```

**output:**
`0
555`
**olacaktır. y değeri 556 olmayacaktır. && operatörünün sol operandı lojik yanlış olduğu için sağ operand yapılmaz.**

### `!!x` operatörü 
`!!x` operatörü C programlama dilinde sıklıkla, bir ifadenin boolean (mantıksal) değerini elde etmek için kullanılır. Bu operatör iki aşamada çalışır:

1. `!x`: İlk olarak, `x` ifadesinin değeri tersine çevrilir. Eğer `x` sıfırdan farklı bir değer ise, `!x` sıfır (0) olur. Eğer `x` sıfır ise, `!x` bir (1) olur.
   
2. `!!x`: İkinci aşamada, elde edilen bu ters değer tekrar tersine çevrilir. Bu da orijinal ifadenin mantıksal karşılığını verir. Başka bir deyişle, `!!x`, `x`'in sıfırdan farklı olup olmadığını kontrol eder ve sonucu bir (true) veya sıfır (false) olarak döndürür.

```c
#include <stdio.h>

int main() {
    int a = 5;
    int b = 0;
    int c = -3;

    printf("a: %d, !!a: %d\n", a, !!a);  // a: 5, !!a: 1
    printf("b: %d, !!b: %d\n", b, !!b);  // b: 0, !!b: 0
    printf("c: %d, !!c: %d\n", c, !!c);  // c: -3, !!c: 1

    return 0;
}
```

Bu örneklerde:

- `a` pozitif bir sayı (5) olduğu için, `!!a` 1 (true) döner.
- `b` sıfır olduğu için, `!!b` 0 (false) döner.
- `c` negatif bir sayı (-3) olduğu için, `!!c` 1 (true) döner.

### Neden Kullanılır?

`!!x` operatörü, genellikle bir değerin boolean karşılığını almak ve bu değeri açıkça 1 veya 0 olarak ifade etmek için kullanılır. Bu yöntem, özellikle bir değişkenin sıfır olup olmadığını kontrol etmek ve sonucu boolean türünde bir değişken olarak saklamak istediğiniz durumlarda işe yarar.

Özetle, `!!x`, bir sayının sıfır olup olmadığını kontrol etmek ve sonucunu boolean (1 veya 0) olarak elde etmek için kullanılır.

## Atama Operatörleri

-  Öncelik yönleri sağdan sola doğrudur. (Right Associative)  
- Yan etkiye sahiptirler.
### `=` Operator

- Değer atama operatörüdür.
- Sol operandı L value expression olmalıdır.
- C dilinde atama operatörleri diğer operatörler gibi bir değer üretir. Atama operatörünün ürettiği değerden faydalanan birçok yapı vardır.
- **Atama operatörlerinin ürettiği değer nesneye atanan değerdir.**


--- 
# 15.08.2024

## Atama Operatörleri Cont'd

### Compound Assignment

- variable = variable op expression;
- Statements with the same variable on each side of the equals sign
- May use the shortcut assignment operators (compound assignment)

|Operator|Operation|Example|Result|
|---|---|---|---|
|+=|Compound  <br>Assignment|x += y|x = x + y|
|-=|Compound  <br>Assignment|x -= y|x = x - y|
|*=|Compound  <br>Assignment|x *= y|x = x * y|
|/=|Compound  <br>Assignment|x /= y|x = x / y|
|%=|Compound  <br>Assignment|x %= y|x = x % y|
|&=|Compound  <br>Assignment|x &= y|x = x & y|
|^=|Compound  <br>Assignment|x ^= y|x = x ^ y|
|\|=|Compound  <br>Assignment|x \|= y|x = x \| y|
|«=|Compound  <br>Assignment|x <<= y|x = x << y|
|»=|Compound  <br>Assignment|x >>= y|x = x >> y|

### Sequence Point

- Kendinden önceki kodun yürütülmesi sonucu oluşulacak yan etki gerçekleşmiş olmak zorundadır.

```c

//code1

++x

//---------- sequence point--------

y = x   // x kesinlikle 1 artmıştır.

//code2
```

- deyim sonu `;` bir sequence pointtir.
- `if`  parantezi bitimi de bir seq. pointtir.
- `for` parantezi bir sequence pointtir.
```c

x = 40;
if(x++ > 10){
	a = x;
	
}
else{
	b = x;
}
```

- **Bazı operatörler sequence point oluşturur.**
	- Logic and operatörü `&&`
	- Logic or operatörü `||`
	- Ternary Operator
	- Comma Operator `,`
	
- Bir nesne eğer bir yan etkiye maruz kalıyorsa ve bir seq. point olmadan kullanılırsa **undefined behaviour** durumu oluşur!!
```c
int x = 5;

int y = ++x + x;  //side-effect sonrası seq. point yok.

```

```c
int x = 5; 
x = x++;    // Undefined Behaviour (atama operatörü bir seq. point değildir.)
```

- **Öncelik parantezi bir seq. point oluşturmaz.**

```c
int x = 5;
int y = x + (x = 9);
```

- Yukarıdaki örnek bir **undefined behaviour** olur.

- C ve C++ dilleri arasında sequence point tanımı hakkında farklılıklar vardır.

### Comma `,` Operatörü

- Bazı yerlerde operatör, bazı yerlerde seperatör olarak görev yapar.

```c
foo(int a, int b)    // Seperator

-----------

int a, b;  // Seperator

----

int arr[] = {1,2,3,4,5}; // Seperator


```

- En düşük öncelikli operatördür.
- Virgül operatörü bir ifade oluşturur ve ifade içinde virgülden önce bir seq. point vardır.
```c
int y = 10;
int x = 7;

y++; x = y;

y++, x = y; // Virgül operatörü bir seq. pointtir ve bu ifade yukarıdaki ifadeyle aynıdır.

```

- İfadeleri virgül operatörü ile birleştirerek bir deyim haline getirdiğimizde ayrı ayrı yazmak ile arasında fark yoktur.
```c
temp = x, x = y, y = temp;

```

- Öncelik parantezi ile kullanıldığında en sondaki değeri alır.

```c

int foo(int)

int arr[10] = {{0,1,2,3,4,5,6,7,8}};


int main(void){

	foo((2,5));   // 5 ile fonksiyon çağırılır.

for(int i = 0; i < 10 ;++i){

	printf("%d",arr(i)); // 8 0 0 0 0 0... yazdırır.
	}

}
```

- **Operatör önceliği hangi işlevin önce yapılacağı anlamına gelmez!!**

## Control Deyimleri

- `if` statement
- `while` statement
- `do` statement
- `for` statement
- `continue` statement
- `break` statement
- `switch` statement
- `goto` statement
- `return` statement

### `if` Deyimi
- En çok kullanılan kontrol deyimidir. 
- Parantez içinde bir **expression** olmak zorundadır.
```c
if(x < 10){

//code
}
```

- Eğer sonunda süslü parantezler `{}` ile blok halinde kullanılmaz ise koşul yalnızca if deyiminden sonraki statement ile ilişkilidir. 
```c
if (exp)
x++; y++;                          /*Bu örnekte if deyimindeki exp logic 1 olduğunda yalnızca x++ statement'ı gerçekleşecektir.*/
Z++;


if (exp)
x++, y++, Z++;                          /*Bu örnekte if deyimindeki exp logic 1 olduğunda 3 statement da gerçekleşecektir.*/
```
- zero- nonzero bir deyimdir. 
```c
int a = 5;
if(a){
	printf("necati");   // Bu ifade ekrana necati yazdırır. Çünkü a nonzero bir değere sahiptir.
}
```


```c
if (foo() != 0)
	statement;

if(foo())
	statement;

// Yukaridaki iki ifade aynıdır. Çünkü if deyimi zero-nonzero bir deyimdir.

```

```c
if(10 < x < 20) // always true (10 <x) ifadesi 0 veya 1 değeri döndürür.
```

```c
if (x != 5 || x != 19) // always true
```

```c
if (foo)    // foo fonksiyonu çağırılmaz ama dogru yazısı ekrana yazdırılır.(Ileride işlenecek derslerde daha detaylı anlatılacak.)
	printf("dogru\n");
```

```c
int main(void){
	double d = 0.;
	for(int i = 0; i < 10; ++i){
		d += 0.1;
	}
	if(d == 1.){
		printf("dogru\n")
	}
	else{
		printf("yanlis\n");    // ekrana yanlış yazısı bastırılır
	}
}
```

---
# 16.08.2024

## if-else Deyimi

```c
if(expr)
	statement_t;    /*Expression logic 1 ise statement_t calisacak*/
else
	statement_f;    /*Expression logic 0 ise statement_f calisacak*/
```

- Blok yapısı `{}` yoksa if-else yapısında if ifadesi statement içermek zorundadır.
```c
if(expr)  
else              /*Syntax error*/
	statement_f; 


if(expr) 
	; // null statement
else              /*No error but not recommended*/
	statement_f; 
```
- Yukarıdaki örnekte null statement yerine içi boş blok kullanılması önerilmektedir.


### Dangling else

```c
#include <stdio.h>

int main(){

	if(x > 10)
		if(y > 20)
			++x;
    else                   /*Burdaki else içteki if deyimine aittir.*/
	    ++y; 
    return 0;
}
```

- Bu gibi durumların da karmaşıklığı nedeniyle blok `{}` kullanımı önerilir.

## else-if Ladder(Cascaded if)
- else-if merdiveni denilmesinin sebebi eski zamanlarda aşağıdaki şekilde yazılmasıdır.

```c
if (x == 2)
	a = 5;
else
	if (x == 7)
		b = 9;
	else
		if(x == 12)
			++c;
		else
			if() //...
	
```

- Günümüzdeki kullanımı:
```c
if (exp1)
	a = 5;
else if (exp2)
	b = 9;
else if(exp3)
	++c;
else if(exp4) //...
```

## Input-Output Functions (Additions)

- Unformatted Input-Output Functions:
	- `getchar`
	- `putchar`
	- Bu iki fonksiyon için `stdio.h` kütüphanesi eklenmelidir.

#### getchar

- standart inputtan bir karakter alır. O karakteri return eder.

```c
#include <stdio.h>

int main(){

	printf("bir karakter girin: ");
	int ch = getchar();
	printf("ch = %d\n",ch);

    return 0;
}
/*Yukardaki örnekte ekrana girilen değerlerdeki ilk karakteri detect edip onun ascii karakter numarasını yazdırır.*/
```

>[!NOTE]
>program sonlandırıldığında bile standart buffer içerisinde hala değer tutulmaya devam eder. Mesela getchar() fonksiyonu 3 kez çağırılırsa, ilk çağırıldığında 1. karakteri sonra 2. ve daha sonra 3. karakteri ekrana yazdırır.

```c
#include <stdio.h>

int main(){

	printf("bir karakter girin: ");
	int ch = getchar();
	printf("ch = %d\n",ch);

	ch = getchar();
	printf("ch = %d\n",ch);

	ch = getchar();
	printf("ch = %d\n",ch);
    return 0;
}
```

kod derlendiğinde standart inputa **`123`** yazarsak çıktısı aşağıdaki gibi olacaktır:

```c
bir karakter girin: 123
ch = 49
ch = 50
ch = 51
```

- getchar ile scanf fonksiyonları aynı buffer'ı kullanır.


```c
#include <stdio.h>

int main(void){

	printf("bir tam sayi giriniz:");
	int c;
	while((c = getchar()) != '\n'){
		printf("%d\n",c - '0');
	}
}
```

out:
```c
bir tam sayi giriniz:654321
6
5
4
3
2
1
```
---
>[!IMPORTANT]
> AŞAĞIDA ÖRNEK BİR MÜLAKAT SORUSU BULUNMAKTADIR:

SORU: pozitif bir tam sayının üçe bölünüp bölünmediğini kontrol et ve ekrana yazdır fakat giriş 30 basamaklı bile olabilir.

```c
#include <stdio.h>

int main(void){

	printf("bir tam sayi giriniz:");
	int c;
	int sum = 0;
	while((c = getchar()) != '\n'){
		sum += c - '0';
	}
	if(!(sum % 3)){
		printf("evet uce tam bolunur\n")
	}
	if((sum % 3)){
		printf("hayir uce tam bolunmez\n")
	}
}
```

---
#### putchar

- Verilen int türünden parametreyi standart output'a yazar.
- Printf gibi variadic bir fonksiyon değildir.
```c
#include <stdio.h>
int main(void){
  putchar(65);
  putchar('\n');
  putchar('A');

}
```
out:
```c
A
A
```

```c
#include <stdio.h>
int main(void){
	for(int cnt = 0; cnt <= 128; ++cnt){
		putchar(cnt);
	}

}
```

**`putchar(cnt);` yerine `printf("%c",cnt);` statement'ı ile de aynı sonuç alınabilir.**


## Test Fonksiyonları

- zero-nonzero değer döndürür
- Genelde `is` ile başlarlar. (`isprime()`)
- Biz de test fonksiyonu yazarken bu minvalde oluşturmalıyız.

```c
int iseven(int x){

    return (!(x % 2));

}
```

### Artık Yıl Testi (Leap Year)
- Artık yıl olma şartı:
	- 4 e tam bolünenlerden
		- 100 e tam bölünmeyenler
		- 400 e tam bölünenler

```c
int isleap(int y){
return (y % 4 == 0) && ((y % 100) || (y % 400 == 0));
}
```

### Perfect Number Testi

```c
int isperfect(int y){
	int sum_div = 0;
	for(int i = 1; i < (x/2); ++i){
		if(y % i == 0){
			sum_div += i;
		}
	}
	return (sum_div == y);
}
```

## <ctype.h> Kütüphanesi
- **zero-nonzero değer döndürürler.** `(True = non-zero // false = zero)`
- Bu kütüphanedeki iki fonksiyon hariç tüm fonksiyonlar **karakter test fonksiyonlarıdır.**
- int isupper(int c) büyük harf test fonksiyonu
- int islower(int c) küçük harf test fonksiyonu
- int isdigit(int c) rakam test fonksiyonu
- int isalpha(int c) küçük veya büyük harf test fonksiyonu
- int isalnum(int c) rakam veya harf karakteri test fonksiyonu
- int isxdigit(int c) hex test fonksiyonu
- int isspace(int c) boşluk karakterlerinden biri mi testi  (new line, carrier return, horizonal and vertical tab and space character)
- int isblank(int c) yalnızca space ve yatay tab testi
- int ispunct(int c) yazıdırabilir karakterlerden alphanumeric olmayanların test fonksiyonu
- int isprint() or isgraph() yazıdrılabilir karakterlerin testi
- int iscntrl() kontrol karakter testi

```c
#include <stdio.h>
#include <ctype.h>
int main(void){

	int ch;
	printf("bir karakter girin:");
	ch = getchar();
	if(isupper(ch)){
		printf("buyuk harf karakter\n");
	}
	else{
		printf("buyuk harf degil\n");
	}
}

```

---
# 20.08.2024

### ctype Kütüphanesindeki Dönüşüm Fonksiyonları

- toupper -> argümanı küçük harf karakter ise onu büyük harfe dönüştürür, argümanı büyük harf ise kendisini döndürür.
- tolower  ->  argümanı büyük harf karakter ise onu küçük harfe dönüştürür, argümanı küçük harf ise kendisini döndürür.
---
**Ek Bilgi**: **`Windows.h`** kütüphanesinde bulunan **Sleep**
fonksiyonu delay özelliğine sahiptir.

---

## Döngü Deyimleri (Loop Statements)

- Bir kod parçasının yinelenmeli olarak tekrar edilmesini sağlar
	- while
	- do-while
	- for
- Yardımcı döngü deyimleri:
	- break statement
	- continue statement

### while Statement
- zero-nonzero bir statement'tir.
- parantez içinde bir `expression` olmak zorundadır.

```c
while(exp)
	statement;
```

```c
int main(void){

int i = 0;

while(i < 10){
	printf("%d",i);
	++i;
	
	}

}
```

- Sık kullanılan bir yapı:
```c
int main(void){

int ch;

printf("bir yazi giriniz");

while((ch = getchar()) != '\n'){
	printf("%c %d",ch,ch);
	
	}

}
```

---
***Sık sorular bir soru:***

Armstrong sayısı: Bir abc sayısı eğer `a^3 + b^3 + c^3 = abc` şeklinde yazılabiliyorsa o sayı Armstrong sayısıdır.  Veya abcd sayısı için `abcd = a^4 + b^4 + c^4 + d^4` 

**Soru:** 3 BASAMAKLI ARMSTRONG SAYILARINI EKRANA YAZDIRINIZ.

```c
#include <stdio.h>

int main(void){

    int sayi = 100;

    while(++sayi < 1000)
    {
    	int a = sayi / 100;
    	int b = (sayi % 100) / 10;
    	int c = sayi % 10;
    	int result = (a * a * a) + (b * b * b) + (c * c * c);
    	if(result == sayi)
    	{
    		printf("%d bir armstrong sayisidir\n",sayi);
    	
    	}
    }

}

```

---
**Sürekli karıştırdığım pre-increment, post-increment konusu hakkında detaylı bir örnek:**

```c
int main(void){
	int x = 0;
	while(x++ < 5){
		printf("%d",x);    // output:1,2,3,4,5
	}

}
int main(void){
	int x = 0;
	while(++x < 5){
		printf("%d",x);    // output:1,2,3,4
	}

}

```

Bu iki kod arasında fark olmasının nedeni, `++x` ve `x++` ifadelerinin farklı işleyişinden kaynaklanmaktadır. Bu durum, C programlama dilindeki "arttırma" (increment) operatörlerinin nasıl çalıştığını anlamayı gerektirir. İşte detaylı bir açıklama:

####  **Önce Arttırma (`++x`)**
```c
int main(void){
    int x = 0;
    while(++x < 5){
        printf("%d",x) ;
    }
}
```
Bu kodda `++x`, "önce arttırma" (pre-increment) operatörüdür. Bu operatör, `x`'in değerini önce 1 arttırır, sonra bu arttırılmış değeri kullanır. Kodun işleyişi şu şekildedir:

- İlk başta `x = 0` olduğu için, `++x` ifadesi `x`'i önce 1 yapar, sonra bu değeri döndürür.
- `while` döngüsünün koşulu her seferinde bu yeni değeri kullanarak kontrol edilir. Bu durumda `x` sırasıyla 1, 2, 3, 4 olur.
- `x` 5 olduğunda `while` döngüsü koşulu sağlanmadığı için döngü sonlanır.

**Çıktı:** `1234`

####  **Sonra Arttırma (`x++`)**
```c
int main(void){
    int x = 0;
    while(x++ < 5){
        printf("%d",x) ;
    }
}
```
Bu kodda `x++`, "sonra arttırma" (post-increment) operatörüdür. Bu operatör, `x`'in mevcut değerini döndürür, ardından `x`'i 1 arttırır. Kodun işleyişi şu şekildedir:

- İlk başta `x = 0` olduğu için, `x++` ifadesi önce 0 değerini döndürür, ardından `x` 1 arttırılır.
- `while` döngüsü mevcut değeri kullanarak koşulu kontrol eder, ancak `printf` ifadesine gelindiğinde `x` zaten arttırılmış olur. Bu durumda `x` sırasıyla 1, 2, 3, 4, 5 olur.
- `x` 5 olduğunda, `while` koşulu hala sağlandığı için bir kez daha döngü çalışır ve `5` yazdırılır. Ancak, döngü bitiminde `x` 6 olur ve bir sonraki döngü başında `while` koşulu sağlanmaz ve döngü sonlanır.

**Çıktı:** `12345`

####  **Özet**
- `++x`: Değeri önce arttırır, sonra koşulu kontrol eder ve kullanır.
- `x++`: Koşulu kontrol ettikten sonra değeri arttırır, sonra sonraki işlemde bu yeni değeri kullanır.

Bu fark, özellikle döngülerde ve karşılaştırmalarda önemli olabilir çünkü değişkenin değerinin ne zaman arttırıldığına bağlı olarak programın akışı değişir.


---
#### **Önemli bir fonksiyon**:
- Bu fonksiyon standart buffer da bulunan kullanılmayan karakterlerin silinmesini sağlar.
- `EOF` yerine burda `-1` değeri de yazılabilirdi.
```c
void clear_input_buffer(void){

	int ch;
	while(getchar() != '\n' && ch != EOF)
		;    // null statement

}

```

##### **Çalışma mantığı:**
`getchar()` fonksiyonu, standart giriş (genellikle klavye) tamponundaki karakterleri birer birer okur ve ASCII değerini döner. Bu işlem sırasında okunan karakter tampondan çıkarılır, yani tampondan silinir. 

Fonksiyonun tamponu nasıl temizlediğini anlamak için adım adım açıklayalım:

##### **Giriş Tamponu ve `getchar()` Fonksiyonu:**
   - **Giriş tamponu (input buffer)**: Kullanıcı klavyeden bir şeyler yazdığında, bu veriler önce bir tamponda (buffer) tutulur. Bu tampon, basılan her tuşu sırayla kaydeder. Örneğin, kullanıcı "123\n" yazarsa, tamponda `123\n` karakterleri bulunur.
   - **`getchar()`**: Bu fonksiyon, tampondaki ilk karakteri okur ve ASCII değerini döner. Ancak, aynı zamanda bu karakteri tampondan çıkarır (temizler). Yani, `getchar()` çalıştığında, tamponda kalan karakter sayısı bir azalır.

##### **Tamponu Temizleme İşlemi:**
   - Fonksiyonda kullanılan `while(getchar() != '\n' && ch != EOF)` döngüsü, tampondaki karakterleri tek tek okur (ve böylece tampondan çıkarır). Döngü, `getchar()` fonksiyonunun döndürdüğü karakter `'\n'` (satır sonu) olana kadar devam eder.
   - Her `getchar()` çağrısı, tampondan bir karakter alır ve onu yok eder. Bu şekilde, tampon boşalana veya satır sonu karakterine (`'\n'`) ulaşılana kadar döngü devam eder.

##### **Örnekle Açıklama:**
   - Diyelim ki kullanıcı "abcde\n" yazdı. Bu durumda, tamponda `a`, `b`, `c`, `d`, `e` ve `\n` karakterleri bulunur.
   - `getchar()` çağrıldığında önce `a` karakteri okunur ve tampondan çıkarılır. Geriye `bcde\n` kalır.
   - Döngü devam eder, `b`, `c`, `d` ve `e` karakterleri sırayla okunur ve tampondan çıkarılır.
   - Son olarak, `\n` karakteri okunur ve döngü sona erer. Bu noktada tampon tamamen temizlenmiş olur.

##### **Sonuç:**
   - Fonksiyonun yaptığı işlem, tampondaki kullanılmamış karakterleri `getchar()` ile tek tek okuyup onları yok etmektir. Bu sayede, tampon temizlenmiş olur ve sonraki `getchar()` çağrıları yeni girişleri bekler. 
- Bu, istemediğiniz karakterlerin giriş tamponunda kalmasını ve programınızın beklenmedik şekilde davranmasını önler.

---
#### Güzel Bir Örnek:

- Girilen bir hex sayının decimal karşılığını yazdıran kod:
```c
#include <stdio.h>

#include <ctype.h>

  

int main(void)

{

  

    int x;

    int c;

    int temp = 0;

    // printf("bir hex sayi giriniz ");

    while ((c = getchar()) != '\n'){

        if (isdigit(c)){

            temp = temp * 16 + c - '0';

  

        }else if (isxdigit(c)){

  

            temp = temp * 16 + toupper(c) - 'A' + 10;

	  }
	}
    x = temp;

    printf("x = %d\n", x);

}

```

>[!NOTE]
>Yukarıdaki örnekte `c = getchar()` ifadesi öncelik parantezine alınmaz ise **operatör önceliği** dolayısıyla ifade `while (c = (getchar() != '\n'))` bu şekilde değerlendirilir. Bu da kodun işleyişinde tamamen hataya sebep olur. **Operatör önceliği çok önemli!**

---
# 22.08.2024

## Bir döngüden nasıl çıkılabilir?

- Kontrol ifadesinin yanlış olması ile
- `return` statement
- `break` statement
- `goto` statement
- `exit` ve `abort` fonksiyonları (ilerde görecez)

## `break` statement
- döngüyü sonlandıran statement olarak geçer. 
- Döngünün gövdesinde olduğu zaman döngüyü sonlandırır.
- Döngü ve switch içerisinde kullanılır.
- Kullanımı basittir.
```c
while(exp){

	//statement1;
	//statement2;
	//statement3;
	if(c_ex){
		break;
	}

}

//statement x;    

```

- Yukarıdaki örnekte görüldüğü gibi break keyword ü çalıştığı zaman program akışı *statement x* 'e yönlendirilir.

---
#### Güzel Bir Örnek:

Amaç: Klavye sadece hex karakterlere kilitlenmek isteniyor.

```c
#include <stdio.h>

#include <ctype.h>

#include <conio.h>

int main(void)
{
    int cnt = 5;
    
    printf("5 hex karakter giriniz: ");

    int ch;
    
    while (cnt--)

    {
        while (1)

        {
            ch = _getch();
            
            if (isxdigit(ch))
            {
                break;
            }
        }
        putchar(ch);
    }
}
```

**Not:** `_getch()` fonksiyonu **standart olmayan** `conio.h` kütüphanesinde bulunan ve echo yapmayan bir non-lined buffer bir fonksiyondur. **(yazılan değerler görülmez ve enter tuşuna basmaya gerek yoktur.)** 

---
#### Güzel Bir Örnek 2
İstenen:
ekranda sürekli `bir tam sayı girecek misiniz? (e), (h)` çıktısı olsun. e girilirse `bir sayi giriniz: ` şeklinde olsun, h girilirse program dursun. Her seferinde ortalamayı, min ve max ı göstersin.

**Benim yazdığım kod:**

```c
#include <stdio.h>
#include <ctype.h>
#include <conio.h>

int main(void)

{
    int i = 0;
    int ch_1 = 0;
    int ch_2 = 0;
    int avg = 0;
    int sum = 0;
    int max = 0;
    int min = 0;
    while (1)
    {

        printf("bir tam sayi girecek misiniz (e) (h): \n");
        if ((ch_1 = _getch()) == 'h')
        {
            break;
        }
        else if ((ch_2 = _getch()) == 'e')
        {
            while (1)
            {
                printf("tam sayiyi girin: ");
                scanf("%d", &ch_2);
                i++;
                if (i == 1)
                {
                    max, min = ch_2;
                }
                if (ch_2 > max)
                {
                    max = ch_2;
                }
                if (ch_2 < min)
                {
                    min = ch_2;
                }
                sum += ch_2;
                avg = temp_avg / i;
                
                printf("toplam %d sayi girdiniz\n avg: %d\n max: %d\n min: %d\n", i, avg, max, min);
            }
        }
        else
        {
            printf("Gecersiz sayi.\n");
            break;
        }
    }
}
```

Hocanın yazdığı kod:

```c
				/* SEVİNDİRİCİ NOT: HOCANIN YAZDIĞI KOD NEREDEYSE BENİMLE AYNI. UFAK FARKLILIKLARI ASAGIYA EKİYORUM */
#include <stdio.h>
#include <ctype.h>
#include <conio.h>

int main(void)

{
    int i = 0;
    int ch_1 = 0;
    int ch_2 = 0;         /*ch_2 ismi yerine daha dogru olan "val" isimlendirmesini kullanmış*/
    int avg = 0;
    int sum = 0;
    int max = 0;
    int min = 0;
    while (1)     /*while(1) yerine while((ch_1 =_getch()) != 'e' && (ch_1 = _getch()) != 'h') yaparak programi geçersiz girişte durdurmak                                                                                                             yerine tekrar giriş istiyor.*/
    {

        printf("bir tam sayi girecek misiniz (e) (h): \n");
        if ((ch_1 = _getch()) == 'h')
        {
            break;
        }
        else if ((ch_2 = _getch()) == 'e')
        {
            while (1)
            {
                printf("tam sayiyi girin: ");
                scanf("%d", &ch_2);
                i++;
                if (i == 1)
                {
                    max, min = ch_2;
                }
                if (ch_2 > max)
                {
                    max = ch_2;
                }
                if (ch_2 < min)
                {
                    min = ch_2;
                }
                sum += ch_2;
                avg = temp_avg / i;
                
                printf("toplam %d sayi girdiniz\n avg: %d\n max: %d\n min: %d\n", i, avg, max, min);
            }
        }
        else
        {
            printf("Gecersiz sayi.\n");
            break;
        }
    }
}
		
```

---


## `continue` Statement

- **`continue` statement'ı kendinden sonraki statement'lerin gerçekleştirilmeden döngünün bir sonraki adımına geçilmesini sağlar.**
- break statement gibi yalnzıca terminator token'ı (;) koyulması yeterlidir.
- `continue` yalnızca döngü içerisinde kullanılır.

```c
while(expr){

	statement1;
	statement2;
	statement3;
	if(!isprime(x)){
		continue;
	}
	statement4;
	statement5;
/*Bu durumda statement 4 ve 5 yalnızca x in asal olduğu durumda yapılacak. */
}
```

- Az önce yaptığımız örnekte null pointer yerine `continue` deyimi kullanılabilirdi.
```c
#include <stdio.h>
#include <ctype.h>
#include <conio.h>

int main(void)

{
    int i = 0;
    int ch_1 = 0;
    int ch_2 = 0;         /*ch_2 ismi yerine daha dogru olan "val" isimlendirmesini kullanmış*/
    int avg = 0;
    int sum = 0;
    int max = 0;
    int min = 0;
    while((ch_1 =_getch()) != 'e' && (ch_1 = _getch()) != 'h')
	    continue; // bir önceki örnekte continue yerşine null pointer (;) kullanılmıştı.
    {

        printf("bir tam sayi girecek misiniz (e) (h): \n");
        if ((ch_1 = _getch()) == 'h')
        {
            break;
        }
        else if ((ch_2 = _getch()) == 'e')
        {
            while (1)
            {
                printf("tam sayiyi girin: ");
                scanf("%d", &ch_2);
                i++;
                if (i == 1)
                {
                    max, min = ch_2;
                }
                if (ch_2 > max)
                {
                    max = ch_2;
                }
                if (ch_2 < min)
                {
                    min = ch_2;
                }
                sum += ch_2;
                avg = temp_avg / i;
                
                printf("toplam %d sayi girdiniz\n avg: %d\n max: %d\n min: %d\n", i, avg, max, min);
            }
        }

    }
}
```

## do-while Döngü Deyimi

```c
while(1) {
	statement;
	statement;
	statement;
	statement;
	statement;
	if(!expr){
		break;
	}
}

```

- `do-while` döngü deyimi yukarıdaki while döngüsü ile oluşturulmuş kod ile aynı anlama sahiptir.

```c
do {
	statement;
	statement;
	statement;
	statement;
	statement;
} while(expr);

```

- **`do-while` ile `while` arasındaki temel fark `do-while` döngü deyiminde döngünün en az bir kere yapılma garantisi vardır.** `while` döngüsünde böyle bir garanti olmak zorunda değildir.

```c
int ndigit(int x){

	int digit_count = 0;
	do {
		++digit_count;
		x /= 10;
	} while(x != 0)
	return digit_count;
}

```

---
# 27.08.2024
## for Döngü Deyimi

- Aşağıda `for` döngüsünün `while` kullanılarak temsil edilmesi gösterilmiştir. 

```c
int i = 0;

while(i < 10){

	statement;
	statement;
	statement;
	statement;
	++i;
}
```

- Diğer döngülerden çok daha fazla kullanılmasının sebebi kompakt olmasıdır. Kontrolü döngü içinde sağlanabilmektedir.

### Genel Sentaks

```c
for(ex1;ex2;ex3)
	statement;
```

- Sıklıkla aşağıdaki gibi kullanılır:
```c
int main(void){
	int i;
	for(i = 0; i < n; ++i)
	statement;
}
```

- `for` döngüsünde eğer 2. ifade yoksa 2. ifade yerine `1` yazılmasıyla eşdeğerdir. (sonsuz döngü)

- C99 standardı ile birlikte döngü değişkeni for parantezi içinde tanımlanabilmektedir.

```c
int main(void){
	for(int i = 0; i < n; ++i)
	statement;
}
```

- Aradaki fark `scope`'dur. Yukarıdaki ifadede bir önceki örneğe nazaran i değişkeni yalnızca döngü içerisinde kullanılır.
--- 
### Garip bir kural:
```c
int main(void){
	for(int i = 0; i < 10; ++i){
		int i = 68;
	}
}
```

- Yukarıdaki i değişken tanımlaması C dilinde  sentaks hatası **değildir**.
- Derleyici kodu aşağıdaki gibi yorumlar:
```c
int main(void){
	for(int i = 0; i < 10; ++i){
		{
		int i = 68;   // Name Hiding
		}
	}
	
}
```

- Bu şekilde i değişkenlerinin scope'u farklıdır.
---
- Özel durumlar hariç her zaman 1. kullanım yerine 2. kullanımı tercih edin.
1.
```c
for(int i = 1; i <= n; ++i) // 1. kullanım

for(int i = 0; i < n; ++i) // 2. kullanım

```

- For döngüsü her zaman birer birer arttırılmak/azaltılmak zorunda değildir.
```c
for(int i = 1; i <= n; i += 2)
```

>[!NOTE] Bu kısımda birçok algoritma örneği verildi. Bunların hepsini not almadım. Çünkü Necati Hoca bu örnekleri github'da ilerleyen zamanlarda paylaşacak.


## Ternary Operator (Koşul Operatörü)

- Bir öperatördür. **Deyim değildir.**
- Öncelik sıralaması sağdan sola doğrudur. (birden fazla ternary operator kullanıldığı durumlar için)
- 3 operanda sahiptir.
```c
op1 ? op2 : op3
```

- 1. öperatör lojik olarak değerlendirilir. Doğru ise op2, yanlış ise op3 üretilir.
```c
x > 0 ? x : -x  // Mutlak değer alma işlemi
```

```c
x > y ? x : y  // Max değer  işlemi
```

### Kullanıldığı tipik senaryolar
- 1. Bir değişkene bir koşula bağlı olarak iki değerden birini  ilk değer olarak vermek veya bir değişkene bir koşula bağlı olarak iki değerden birini atamak.

```c
int min = x < y ? x : y;  // Max değer  işlemi
```

- Not: son noktalı virgül için paranteze ihtiyaç **yoktur. (operatör önceliği)**
```c
for(int i = x < y ? x : y; i < 10; ++i)

```
- Yukarıdaki örnekte yapılan işlem if-else yapısı ile yapılamaz. Çünkü istenilen işlem kontrol deyimiyle değil, operatör ile yapılması gereken bir işlemdir.

- 2. Bir fonksiyonu bir koşula bağlı olarak farklı argümanlar ile çağırmak.

```c
--------------------------------------
if(x > y)
	foo(x);
else
	foo(y);
--------------------------------------
foo(x > y ? x : y);
--------------------------------------
Yukarıdaki iki örnek aynı anlama sahiptir.

```

- 3. Return Statement: 

```c
int foo{

	//code...

	if(x > 0)
		return a;
	else 
		return b;
}


int foo{

	//code...
	
return x > 0 ? a : b;
}
```

 - Başka bir operatörün operandı olarak da kullanılabilir.

```c
if(isleap(y) ? 366 : 365)
```

- Tüm senaryoların ortak noktası: koşul operatörünün ürettiği değeri kullanıyoruz.

- **C dilinde R value expression olarak geçer.**

```c
int main(void){

	int x = 10, y = 20, z = 30;
	
	if(x > 5)
		y = 0;
	else
		z = 0;
/////////////////////////////////////////

(x > 5 ? y : z) = 0;  // Bu ifade, C dilinde geçersiz bir ifadedir. Syntax Error
//Cpp dilinde geçerli bir ifadedir.
	
}
```

```c
int main(void){

int x = 13


int a = x == 5 ? 121:
		x == 7 ? 93:
		x == 13 ? 145: 6;
/////////////////////////////////////////
int b;

if (x == 5)
	b = 121;
else if (x == 7)
	b = 93;
else if (x == 13)
	b = 145;
else
	b = 6;

/////////////////////////////

// Yukarıdaki iki ifade aynı anlamı taşımaktadır. Ternary operator right associative bir operatördür.
	
}

```

---
# 29.08.2024

## Function Prototype(s)

```c
int func(int, int); // Fonksiyon bildiriminde fonksiyon parametrelerine isim vermek zorunlu değildir.
int func(int a, int b); // Buradaki a ve b değerleri yalnızca fonksiyon bildiriminde tanımlıdır. (Function prototype scope)
```
- Bu bildirim derleyiciye fonksiyonu bildirir.
### Fonksiyon Bildirimi ile Fonksiyon Tanımının Farkı
- Derleyici fonksiyon tanımı ile ilgilenmez. Fonksiyon bildirimi ile ilgilenir. Linker'ın görevini yapabilmesi için fonksiyona ait bildirimden bir external reference oluşturur.
- Genelde bu iki kavram source ve header adlı ayrı dosyalarda bulunur.

### Header Dosyalarında:

- Client kodların çağırmasının istediğimiz fonksiyonların prototipi (bildirimi).
- Global değişkenklerin bildirimi
- User defined type tür bildirimleri
- Type alias (tür eş isimleri)
- Macro

>[!NOTE] Derleyici veya linker source code a ihtiyaç duymaz. Örneğin standart library fonksiyonlarının hiçbirinin source code u bulunmaz. Burada ihtiyaç olan şey fonksiyon prototipi ve derlenmiş .obj dosyasıdır. Yani bize verilen printf gibi fonksiyonların source code'u derlenmiş ve derlenmiş hali bize verilmiştir.



## Preprocessor (Önişlemci Program)

- Donanımla alakası yoktur.
- Derleyiciden önce çalışan programdır.
- Kaynak dosyada bulunan kendi directive'lerini yürütür, komutlara ilişkin işlemleri yaptıktan sonra derleyiciye input olarak bir çıktı sağlar.
- Ön işlemci girdisi: Source File
- Ön işlemci çıktısı: Translation Unit
- Translation unit'te önişlemci komutları bulunmaz.

>[!IMPORTANT] ÖNİŞLMECİ C BİLMEZ!!!

 - Number Sign `(#)` ile başlar.
 - Satırdaki white space karakterlerinden sonraki ilk karakter number sign olmak zorundadır.
### Preprocessor Directives
```
#           Null Directive
#include
#define
#undef
#if
#else
#elif
#ifdef
#ifndef
#endif
#line
#error
#pragma
``` 

- Sonuna noktalı virgül koyulmaz.
- `#if`, `#elif`,  `#ifdef`, `#ifndef`, `#endif`, `#else` komutları koşullu derleme komutlarıdır. **(Conditional Compiling)**
- Koddaki yerleştirmeleri kodun anlamını değiştirir.
- Genellikle kaynak kodun başında olurlar özellikle `#include` komutu.

---
# 30.08.2024

## `#include` Önişlemci komutu

- Include komutuyla ilgili dosyadaki kodların bulunduğu konuma yapıştırılır. Önişlemci komutlarını yürütür.
- İstisnai durum olmadıkça her zaman header dosyaları kullanılır.
```c
#include <stdio.h>
```

- **`< >` kullanımı genellikle derleyici tarafından hazır olarak gelen kütüphaneleri include ederken kullanılır.**
- **`" "` kullanımı ise genellikle external kütüphaneler için kullanılır.**
```c
#include <stdlib.h>
#include "yavuz.h"
```

- `< >` kullanımında derleyici dosyayı **default directory** içerisinde arar.
- `" "` kullanımında derleyici dosyayı **project directory** içerisinde arar.

## `#define` Önişlemci Komutu

- Önişlemci programa bir isim tanıtıyoruz. Tanıtılan bu isimlere **macro** denir.
	- Object - Like Macro
	- Function - Like Macro

### Object - Like Macro

```c
#define SIZE 100
```
- Burada önişlemci kod içerisinde `SIZE` bulunan her yere SIZE yerine 100 yazar.
- **ÖNİŞLEMCİNİN SCOPE KAVRAMI YOKTUR.!!**
- Üretimde genellikle macrolar tamamen **büyük harfle** yazılır.
- Önişlemci yerdeğiştirmeyi yazı olarka yapar. Yani:
```c
#define SIZE 100+200
int main(void){
	int x = 7 * SIZE;
	printf("%d",x);
}
```
- Yukarıdaki ifade ekrana `900` değeri bastırır. Önişlemci SIZE yerine kodda 100+200 yazar.
- Öncleik parantezi olsaydı yukarıdaki ifade ekrana `2100` değeri bastırırdı.
- Bir makro içinde başka bir makro ismi geçebilir.
```c
#define NEC     100
#define ERG     NEC + 400
```

- `#define` komutu sonrasında noktalı virgül kullanılmaz.
- Macro bir string literal olabilir.
```c
#deifne MESSAGE    "NOT ENOUGH ARGUMENT"
```

- Bir makroda alt satırdan devam etmek için ters bölü işareti (\) kullanılır.

```c
#define NECATI   130
#define ERGIN    NECATI + 250
#define YAVUZ    100 + ERGIN + \
NECATI
```

- Object like makrolar genellikle bir sabitle yer değiştirilmesi için kullanılır.  (Symbollic Constants)
- Taşınabilirlik sağlar
- Bir değeri bulunmayan makrolar derleyici tarafından silinirler.
```c
#define PUBLIC
#define PRIVATE
#define IN
#define OUT

PUBLIC int foo(IN int x); // Syntax hatası yok!!

int main(void){

}
```

## Functional Macro
- Makronun kullanımı bir fonksiyon çağrısı görüntüsü verir. Fakat yine bu durumda da replacement söz konusudur.

```c
#define SQRT(a,b)
#define SQRT(a)
#define SQRT()
```

```c
#define SQUARE(A)    A * A

int main(void){

	int x = 35;
	int a = SQUARE(x);
	printf("%d", a);
}
```
out: 
`1225`
>[!IMPORTANT] 
>Macro parametreleri açılım listesinde her kullanıldığında parantez içerisinde kullanılmalıdır.
>Özetle: MACRO KULLANIRKEN PARAMETRE DEĞİŞKENLERİNİ PARANTEZ İÇİNE ALIN.

```c
//#define SQUARE(A)    A * A  // Yanlış
#define SQUARE(A)    (A) * (A) // Doğru

int main(void){

	int x = 35;
	int a = SQUARE(x+1);
	printf("%d", a);
}
```
- Program çıktısı yanlış olarak yorumlanan şekilde değerlendirilseydi `71` değerini standart output a yazdırırken, doğru şekilde değerlendirilirse `1296` değerini yazdırır. 
- Yukarıdaki örnekte `#define SQUARE(A)    A * A` ifadesi kullanılsaydı kod şu şekilde olurdu:
```c
int main(void){

	int x = 35;
	int a = x + 1 * x + 1;
	printf("%d", a);
}
```

>[!IMPORTANT]
>Öncelik problemlerinden etkilenmemesi için makroyu dıştan parantez içine alın!

```c
//#define SQUARE(A)    (A) * (A) // Yanlış
#define SQUARE(A)    ((A) * (A)) // Doğru

int main(void){

	int x = 5;
	int a = 100 / SQUARE(x);
	printf("%d", a);
}
```
- Yanlış Implementasyon sonucu:
`100`
- Doğru Implementasyon sonucu:
`4`
```c
#include <stdio.h>
#define MAX(A,B)    ((A) > (B) ? (A) : (B))
#define MIN(A,B)    ((A) < (B) ? (A) : (B))

int main(void){

	int x = 5;
	int y = 22;
	int res_max = MAX(x,y);
	int res_min = MIN(x,y);
	printf("max = %d, min = %d\n",res_max,res_min);
}
```

```c
#include <stdio.h>
#define ISUPPER(C) ((C) >= 'A' && (C) <= 'Z')

int main(void){
    
    char x = 'A';
    int res = ISUPPER(x);
    printf("%d",res);

}
```

- Sıkça karşılaşılabilecek bir hata:
```c
#define SQUARE(A)    ((A) * (A)) // Doğru

int main(void){

	int x = 5;
	int a = SQUARE(x++);
	printf("%d", a);
}
```
- Yukarıdaki ifade undefined behaviour olur. Çünkü önişlemci kodu aşağıdaki gibi açar:
```c
int main(void){

	int x = 5;
	int a = x++ * x++;
	printf("%d", a);
}
```
- İki arttırma operatörü arasında sequence point bulunmamaktadır.

>[!NOTE] Bazı kütüphaneler bilerek isteyerek aynı isime sahip macro ve fonksiyon oluştururlar. Kullanıcı istediğini kullanabilir.

```c
#include <stdio.h>

int SQUARE(int x){
	return x * x;

}

#define SQUARE(A)    ((A) * (A)) 

int main(void){

	int x = 5;
	int a = SQUARE(x);  // Makro kullanılır.
	int b = (SQUARE)(x) // Fonksiyon kullanılır
	printf("%d", a);
}
```
- Fonksiyon ismini parantez içine almka syntax ı bozmaz!!
### Neden makro yazıyoruz? Amacı ne?
- Fonksiyon çağrısı giriş kodları, çıkış kodları, argümanlardan parametre kopyalama vs. gibi maliyetli bir işlemdir.  
- Fonksiyonel makro kullanımında ise böyle bir verim maliyeti bulunmamaktadır. Önişlemci tarafından yürütüldükleri için maliyeti çok daha düşük ve hızlıdırlar.
- Özellikle kodu küçük, pure fonksiyonlar için onları makro haline getirmek genellikle çalışacak kod açısından avantaj sağlar.

---

# 03.09.2024

## Önişlemci Operatörleri
- `#`
- `##`
- `defined`
### `#` Önişlemci Operatörü
```c
#define str(x)    #x

int main(void){

	printf(str(kadir));
	//printf("kadir");

// BU İKİ İFADE AYNI ANLAMA GELİR.

}



```
out:
`kadir`

#### String literal ile ilgili Ek Bilgi

>[!NOTE] Eğer string literaller arasında white space harici bir karakter yoksa bu stringler birleştirilir.


```c
printf("Yavuz"
	  "Hanege"
	  "Elazig");

```
out:
`Yavuz Hanege Elazig` 


### `##` operatorü

' ## ' ön işleme operatörü, belirteç yapıştırma işlemini gerçekleştirir. Bir makro genişletildiğinde, her ' ## ' operatörünün her iki tarafındaki iki belirteç, daha sonra ' ## ' ve makro genişletmesindeki iki orijinal belirtecin yerini alan tek bir belirteçte birleştirilir.

```c
// C program to illustrate (##) operator
#include <stdio.h>

// Macro definition using the Token-pasting operator
#define concat(a, b) a##b
int main(void)
{
    int xy = 30;

    // Printing the concatenated value of x and y
    printf("%d", concat(x, y));
    return 0;
}

```

- Önişlemci printf(“%d”, concat(x, y)); ifadesini printf(“%d”, xy); ifadesine dönüştürür.
## Conditional Compiling
- Önişlemcinin bazı komutlarıyla derleyiciye kod seçimi yaptırmak
### `#if` `#elif` `#else` `#endif`

```c
int main(void)
{
#if 1
	printf("necati ergin");

#else 
	printf("yavuz hanege");
#endif
}

```
our:
`necati ergin`


>[!NOTE] `#define NEC` tanımlamasında bir replacement bulunmadığı için NEC makrosu sadece tanımlıdır. DEĞERİ 1 DEĞİLDİR.

###  `ifdef` `ifndef`

```c
#define NEC
int main(void)
{
#ifdef NEC
	printf("necati ergin");

#ifndef NEC 
	printf("yavuz hanege");
#endif
}

```
`necati ergin`

### `#defined`
- Operandı tanımlıysa lojik 1 değerini alır, tanımlı değilse lojik yanlış değerini alır.

```c
#define NEC
int main(void)
{

#ifdef NEC
	printf("necati ergin");

#if defined(NEC) 
	printf("yavuz hanege");
#endif
}

// Yukarıdaki iki ifade aynı anlama gelmektedir.

```

```c
#define NEC

#if kosul1

#elif defined(NEC)

#elif kosul3


#else

#endif

```

- `defined` komutu dile sonradan eklenmiş bir özelliktir. Koşullu derlemede birden fazla koşulu kontrol etme olanağı sağlar. 
- Parantez içindeki koşul doğru ise 1, yanlışsa 0 döndürür.
```c
#define NEC
#define ERG

#if defined(NEC) && defined(ERG)
	//code...
#endif

```


>[!INFO] Header dosyalarını korumak için header guard olarak kullanılabilirler. **(multiple inclusion guard)**

```c
#if !defined NUTILITY_H
#define NUTILITY_H

///... code



#endif

```

### `Undef` İşlemci komutu
- Önişlemci program bu komutu yürüttüğünde eğer daha öncesinde böyle bir makro tanımlıysa o makroyu artık tanımsız kabul ediyor.
- Makro tanımlı değilse bir sorun olmaz.
- Tüm makrolar için geçerlidir. (fonksiyonel, tanımlama vs...)

```c
#undef MAX
#undef SQUARE
```

```c

#define NEC
int main(void)
{

#ifdef NEC
	printf("necati ergin");

#undef NEC
#ifdef NEC
	printf("yavuz hanege");
#endif
}

```
`necati ergin`

- Makrolara "sözde scope" kazandırmak için aşağıdaki gibi bir implementasyon yapılabilir.
```c
#undef SIZE
#define SIZE 100

/* Sözde Scope */

#undef SIZE
#define SIZE 500
```

---
# 05.09.2024

## Predefined Macros

- C89'dan beri var olan predefined macrolar:
```c
__LINE__
__FILE__
__DATE__
__TIME__
__STDC__
```

- `__LINE__` kodun kaçıncı satırında kullanıldıysa o satırın numarası ile yer değiştirir.
- `__FILE__` kaynak dosyanın yolunu string literal olarak yazar.
- `__TIME__` derlenme zamanını verir.
- `__DATE__` derlenme tarihini verir.
- `__STDC__` standart c derleyicileri ile çalıştırıldığında tanımlı olur.
- `__func__` kullanıldığı fonksiyonun adını string litreal olarak döndürebilir.

### `#error` Önişlemci Komutu

- Derleme aşamasında önişlemci sürecinde hata mesajı olarak mesaj döndürür ve program durdurulur.
```c
#include <stdio.h>

int main(void){

#ifndef __STDC__
#error BU PROGRAM C derleyicisi ile derlenmeli.
#endif
}
```

### `#pragma` Komutu

- Derleyicilerin belirli özellikler kazandırabildiği komutlardır. Standart tarafından bu iş için özel olarak ayrılmışlardır.
Örnek:

```c
#include <stdio.h>
#pragma warning(disable:4552)

// warning C4552 : '+' result of expression not used

int main(void){

	int x = 5;
	x + 5;

}

```

- Yukarıdaki örnekte görüldüğü gibi pragma komutu ile istenen uyarı disable edildi. **(Yalnızca Microsoft derleyicisine ait bir pragmadır.)**

#### İleri Düzey Bir Örnek

```c
#include <stdio.h>
#define printf(x)    printf("%d\n",x) 

int main(void){

	printf(4567);

}

```

Burada ekrana `4567` sayısını bastırır. Sebbei ise bir makro replace edildiğinde makronun kendisi çıkarsa o makroyu tekrar açmaz.

## `Switch` Statement

- `else-if` merdiveninin bazı kullanımlarına alternatiftir.
- Kodun daha kolay okunmasını sağlayabilir.
- Kodun daha kolay yazılmasını sağlayabilir.
- Derleyicinin daha etkin kod üretmesini sağlamak.

```c
switch (integer expr){

case 2: 
statement1;
case 6: 
statement2;
case 13: 
statement3;
}
```
- `break` ve `continue` kullanılabilir.
- Her case label'ı unique olmak zorunda. Aynı label a sahip farklı case'ler olamaz.
- Swtich'in içi boş olabilir.(Mantıklı değil ama kurala aykırı da değil.)
- **Her case sonrası bir statement olmak zorunda.**
- Eğer case sonrası break statement yok ise girilen case ve sonrasındaki kodlar çalıştırılır. 

```c
#include <stdio.h>


int main(void){

	int weekday;
	printf("haftanin kacinci gunu : ");
	scanf("%d",&weekday);
	switch(weekday) {
	case 1: printf("pazartesi");
	case 2: printf("sali");
	case 3: printf("carsamba");
	case 4: printf("persembe");
	case 5: printf("cuma");
	case 6: printf("cumartesi");
	case 7: printf("pazar");
	
	}
}

```
Standart inputa 5 değerini verirsek:

`out`
`cumacumartesipazar`

```c
int main(void){

	int weekday;
	printf("haftanin kacinci gunu : ");
	scanf("%d",&weekday);
	switch(weekday) {
	case 1: printf("pazartesi");break;
	case 2: printf("sali");break;
	case 3: printf("carsamba");break;
	case 4: printf("persembe");break;
	case 5: printf("cuma");break;
	case 6: printf("cumartesi");break;
	case 7: printf("pazar");break;
	default: printf("gecersiz gun.\n");
	}
}

```
Standart inputa 5 değerini verirsek:
`out`
`cuma`

- `default` case i en sonda olmak zorunda değil ama genellikle en sonda olur.
- Switch Statement kullanımında genellikle case'ler isimlendirilmiş sabitler (bkz. ENUM) olarak kullanılır.

```c

if(x == 5 || x == 7){
	statement1;
}
else if(x == 9 || x == 13 || x == 17){
	statement2;
}

---------------------------------------

switch (x){

case 5:
case 7: 
	statement1; 
	break;

case 9:
case 13:
case 17:
	statement2;
	break;
}

/* YUKARIDA BULUNAN 2 KOD AYNI İŞLEVİ TAŞIR */

```

- Tek bir tane case olunca block `{ }` kullanılmaması doğru olabilir fakat birden fazla case olduğunda scope u belirlemesi için kullanılması gerekmektedir.

>[!NOTE] Ben genellikle tüm ögeler için bloklama kullanıyorum. Daha az risk oluşturduğundan dolayı. Necati Hoca bu konuda biraz daha özgür bırakıyor öğrencileri.

```c
switch (x) {

case 1: 
statement1;
//fallthrough
case 2: 
statement2;
break;
case 3: 
statement3;
break;
}

```
>[!TIP] Yukarıdaki örnekte 1. case'de break bulunmama sebebinin unutulmuş olmasından değil; bilerek, isteyerek koyulmamış olmasını işaret etmek için genellikle yorum satırı olarak **`//fallthrough`** yazılır.

---
# 06.09.2024

## `goto` Statement

- Katı katıya `goto` deyimine düşman olmamak gerekiyor.
- Kernel kodlarında bir sürü `goto` deyimi bulunur.
- Programın akışını bir başka noktaya yönlendirir. (jump)
	- Long Jump
	- Near Jump

### Syntax

#### Function Scope
- Bir label, kod içerisinde nerede tanımlanırsa tanımlansın, kodun içerisinde **her yerde** kullanılabilir.
- Label kullanımının `goto` haricinde pek bir lojik karşılığı yoktur.
```c
int main(void){

	nec:           //LABEL
		;

}
```

- **Kullanıldığı yerde, programın label'dan sonraki statement'a jump etmesini sağlar.**

```c
int main(void){

	if(expr){
		goto nec;
	}
	statementa;
	statementb;
	statementc;
	statementd;
nec:
	statementx;

}

/*YUKARIDAKİ KODDA IF DEYİMİNİN İÇİNE GİRİLİRSE PROGRAMIN AKIŞI STATEMENTX ADLI STATEMENT'A JUMP EDİLİR.*/

```

- Genellikle iyi kabul edilecek `goto` kullanımlarının hepsinde programın akışı `goto` kullanılan yerden sonrasına jump edildiği kullanımlardır.
```c
int main(void){
nec:                // KÖTÜ KULLANIM!!!
	if(expr){
		goto nec;
	}
	statementa;
	statementb;
	statementc;
	statementd;

}
```

- `goto`'nun en fazla kullanıldığı ve kullanımının doğru kabul edildiği yer:
```c
dongu () {

	dongu(){
	
		dongu(){
		
			if(expr){
				goto yavuz;//break; 
			}
		}
		STATEMENT_A;
	}
	STATEMENT_B;
}
yavuz:
STATEMENT_X;
```

- Yukarıdaki örnekte `break` kullanıldığı durumda yalnızca içinde bulunduğu döngüden çıkar. `goto` kullanarak tüm döngülerden çıkıp STATEMENT_X in gerçekleştirilmesini sağlayabiliriz.
- Bu tür ihtiyaçlarda `goto` yerine flag kullanılabilir. Fakat `goto` kullanılarak çok daha sade bir yapı ile bu işlem gerçekleştirilebilir.

```c
int flag = 0;
dongu () {

	dongu(){
	
		dongu(){
		
			if(expr){
				flag = 1;
				break;
			}
		}
		if(flag == 1){break;}
		STATEMENT_A;
	}
	if(flag == 1){break;}
	STATEMENT_B;
}
yavuz:
STATEMENT_X;
```

- Bir kullanımı daha var fakat o kullanım kursun ikinci yarısında gösterilecek.

## İç İçe Döngüler (Nested Loops)

```c

for(int i = 0; i < 5; ++i){

	for(int k = 0; k < 10; ++k){
	
		printf("i = %d\n k = %d\n",i,k);
	}

}

```

---
### Basit Bir Mülakat Sorusu

```c

for(int i = 0; i < 5; ++i)
	for(int k = 0; k < 10; ++k);
		printf("i = %d\n k = %d\n",i,k);
```
Ekran çıktısı ne olur?
**Cevap:** 
Ekran çıktısı 
`i = 5
k = 10`
olur. Çünkü 2. for döngüsünün sonunda null statement `;` vardır.

---
- İç içe döngülerde fonksiyonlara ayırarak kodun daha anlaşılır hale getirilebilir.

>[!IMPORTANT] Necati Hoca daha erken olsa da kursun ilerleyen süreçlerinde yavaş yavaş [Leetcode](https://leetcode.com/) yazabilirsiniz dedi. 
## Random Number Generation (Rastgele Sayı Üretimi)

- True Random Number Generation
	- Atmosferic Noise ...
	- Deterministik değil
- Sudo Random Number Generation
	- Algoritmik yöntemle rastgele sayı üretimi
	- Deterministiktir. (Aynı input -> Aynı Output)


>[!WARNING]  C'nin standart kütüphanesindeki rastgelelik fonksiyonları profesyonel hayatta kullanım için uygun değildir. Bu fonksiyonlar rastgeleliğin önemli olmadığı ortamlarda kullanılabilir. Yeterli düzeyde fonksiyonlar değildir.

- `stdlib.h` kütüphanesi farklı konularda destekler veren bir kütüphanedir.
- `rand` ve `srand` fonksiyonları da bu kütüphanelerde bulunmaktadır.
```c
int rand(void);
```
- `RAND_MAX` makrosu fonksiyonun üretebileceği max değeri verir.
- Random fonksiyonların inputlarına `seed value` denir. 
- `srand` Seed parametresi ile verilen değeri kullanarak rasgele sayı üreticisini başlatır. Programın içinde rand() fonksiyonu kullanılmadan önce bir kez çağrılmalıdır.
- `rand` fonksiyonu ise parametreye sahip olmayan ve int türünden bir değer döndüren bir fonksiyondur.

```c
int main(void){

	for(int i = 0; i < 100; ++i){
	
		printf("%d\n",rand());
	}

}


```

- Her seed value için farklı random değerler üretilir.

```
#include <stdio.h>
#include <stdlib.h>

int main(void){

	for(int i = 7654; i < 7754; ++i){
		
		srand(i);
		printf("seed value: %d\n",i);
		for(int i = 0; i < 20; ++i){
				
			printf("%d\n",rand());	
		}	
	(void)getchar();
	system("cls");
	
	}
}
```


- 1-6 aralığında rastgele iki zar için dağılım **mod** operatörü ile yapılabilir fakat **profesyonel hayatta kodun uniform açısından doğruluğu için mod operatörü kullanılmaz.**


```
int main(void){

	for(int i = 0; i < 100; ++i){
	
		printf("%d %d\n",(rand() % 6 + 1),(rand() % 6 + 1));
	}

}

```
- Yukarıdaki kodda her zaman aynı sayılar gelecektir.
- Bunu aşabilmek için aşağıdaki gibi bir çözüm uygulanabilir.

```c
#include <time.h>
int main(void){
	srand(time(NULL));

	for(int i = 0; i < 100; ++i){
	
		printf("%d %d\n",(rand() % 6 + 1),(rand() % 6 + 1));
	}

}
```

- time fonksiyonu epoche'dan geçen saniye veya milisaniye (derleyiciye göre değişebilir) sayısını argümanda belirtilen değişkene set eder. Argüman olarka `NULL` verilirse yalnızca bu değeri döndürür. Bu da random number generation için önemli bir true random generator olarak kullanılabilir. (ileride bu kütüphane daha detaylı anlatılacaktır.)

>[!WARNING]  Bu çözümde parametresi `unsigned int` olan bir fonksiyona(srand) `time_t` cinsinden yani Long Long veya Long cinsinden bir değişken veriyoruz. Bu da karmaşıklığa ve derleyicinin uyarı mesajı vermesine neden olur.

```c
void randomize(void){

	srand((unsigned)time(NULL));
}
```

---
# 10.09.2024

- Random number generation olasılık hesaplamalarında da kullanılmaktadır.
- Monte Carlo Yöntemi:

- Problem: Yazı-Tura oyununda yazı gelme olasılığı?
```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "nutility.h"

#define NTOSS 100000
#define HEADS 1

int toss(void){

return rand() % 2;

}

int main(void){
	srand(time(NULL));
	int head_count = 0;
	for(int i = 0; i < NTOSS; ++i){
		if(toss() == HEADS){
			++head_count;
	
		}
	}
	printf("tura gelme olasiligi: %f\n",((double)head_count / NTOSS));
}
```

 ---
### Craps Oyunu Algoritması
**Problem**:
Oyuncu 2 zar atar
- Toplamları:
- 7 veya 11 ise oyuncu kazanır
- 2, 3 veya 12 ise oyuncu kaybeder
- diğer toplamlar geldiğince oyuncu ya ilk zarını atıp kazanacak ya da 7 atıp kaybedecek. 
- Not: Uluslararası kumar win rate oranı: %49.20-%49.50 arasında bir değerdir.
```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "nutility.h"

#define NGAMES 10000000


int roll_dice(void){

	int dice1 = rand() % 6 + 1; // kotu teknik
	int dice2 = rand() % 6 + 1; // kotu teknik
	return dice1 + dice2;

}

int game_(int dice){
	int new_dice;
	while(1){
		new_dice = roll_dice();
		if(new_dice == dice){return 1;}
		else if(new_dice == 7) {return 0;}
	}
	return 0;
}

// returns 1 for win, 0 for loss
int game(void){
	int dice = roll_dice();
	switch(dice){
	case 7:
	case 11: return 1;
	case 2:
	case 3:
	case 12: return 0;
	default: return game_(dice);
	}



}

int main(void){
int win_count = 0;
	for(int i = 0; i < NGAMES; ++i){
		win_count += game();
	
	
	}

	printf("kazanma olasiligi: %f\n",((double)win_count * 100) / NGAMES);

}
```
---

## Type Conversions (Tür Dönüşümleri)

- Implicit Type Conversions
	- Bir talimat yokken yapılan otomatik dönüşümler.
		- Atama Tür Dönüşümleri
		- Basit Aritmetik Dönüşümler
- Explicit Type Conversions
	- Bir conversion talimatı ile yapılan dönüşümler. 

- Sıklıkla hata yapılan bir konudur.

### Basit Aritmetik Tür Dönüşümleri

```c
a + b
x > y
```
- İşlemin yapılabilmesi için derleyici ya a yı b türüne ya da b yi a türüne dönüştürür. 
- Veri kaybı olmayacak şekilde mümkünse yapılır. 
- Her türün bir `rank` değeri vardır.
	- long double
	- double
	- float
	- long long
	- long
	- int
	- short
	- char
	- `_Bool`
	
>[!NOTE] İşaretli tam sayı türlerinde overflow tanımsız davranış olurken, işaretsiz türlerde elde edilen değerin türün max alabileceği değerin bir fazlasına bölünmesi sonucunu verir.(**yüksek anlamlı bytle'lar gider.**)

```c
long long x = 2000000000000;
long long y = 1000;

printf("%llx\n",x * y);
// TANIMSIZ DAVRANIŞ
```



- İşaret Operatörleri:
```c
+x
!x
```

- Taşma olmaması için genellikle daha büyük olan türe dönüştürülür.
- signed - unsigned işleme sokulduğunda **sonuç unsigned olur.**

>[!IMPORTANT] TÜR DÖNÜŞÜMÜ KALICI DEĞİLDİR.

```C
int main(void){

	int x = 10;
	x / 4.96; // Tür dönüşümü double -> int
	x // X'İN TÜRÜ INT'DİR DOUBLE DEĞİL!!
}

```
---
#### Mülakat Sorusu:

```c
#include <stdio.h>
int main(void){
	int x = 10;
	double dval = (x > 5 ? 5 : 5.) / 2;
	printf("dval = %f\n",dval);

}
```

- Yukarıdaki kodun çıktısı `2` **DEĞİL** 2.5 olur.
>[!NOTE] Terminary operatorünün operandları arasında da tür dönüşümü gerçekleşir. 
- 2. ve 3. operandlar arasında tür dönüşümü gerçekleşeceğinden değer `double` hale gelir.
---
### Atma Tür Dönüşümleri:
```c
-------------------------------------
int x = expr; // expression return value not int
-------------------------------------
x = y; // y not int
-------------------------------------
void foo(int);
foo(arg) // arg not int
-------------------------------------
int bar(.....){
-------------------------------------
return expr;//not int 
}
-------------------------------------
```

- Eşitliğin sağ tarafındaki ifade **source type**, sol tarafındaki ifade ise **target type** olarak isimlendirilir.
- **Tür dönüşümü her zaman target type a yapılır.**
- Küçük tam sayı türlerinden büyük tam sayı türlerine dönüşümde bir kayıp olmadığı için herhangi bir önleme ihtiyaç yoktur.
```c
int x = 3614;
long lval = x;
```

- **Büyük tam sayı türünden küçüj tam sayı türüne dönüşüm veri kaybı riski barındırır.**
```c
int x = 0x1acf34;
unsigned short us = x;
```
- Yukarıdaki örnekte x in yeni değeri `cf34` olur.
- Yüksek anlamlı byte'lar gider.
- **Gerçek sayı türlerinden tam sayı türlerine dönüşümde ondalıklı kısım kaybolur.**
```c
double dval = 56.27;

int ival = dval;

printf("%d\n",ival); // ekrana 56 yazdırır.

```

>[!IMPORTANT] Gerçek sayı türlerinden tam sayı türlerine dönüşümde ondalıklı kısım atıldıktan sonra kalan sayı istenen türe sığmıyorsa undefined behaviour olur.

## Type-Cast Operator

- **`(target type)`**
- Tür dönüşüm operatorü ile oluşturulan ifade **R Value Expression** olur.
```c
int main(void){

	int x = 10;
	int y = 3;
	
	double d1 =  x / y;
	double d2  = (double)x / y;
	double d3  = x / (double)y;
	double d3  = (double)(x / y);
	printf("d1 = %f\n",d1);
	printf("d2 = %f\n",d2);
	printf("d3 = %f\n",d3);
	printf("d4 = %f\n",d4);

}
```
***out:***
`d1 = 3.000000`
`d2 = 3.333333`
`d3 = 3.333333`
`d4 = 3.000000`

- Bazı durumlarda yapılan dönüşümün bilerek yapıldığını belli etmek için de kullanılır.
```c

double foo(void);
int main(void){

	float f;
	f = (float)foo(); // Type-cast operatorü kullanılmasaydı da dönüşüm yapılacaktı.
}
```


Not:

```c
int main(void){

	char c = 178;
	if(c == 178) {
		printf("dogru\n");
	}
	else{
		printf("yanlis\n");
	}
	printf("c = %c\n",c);
}
```

***out:***
`yanlis`
`-78`

>[!INFO] Sebebi ise char değişkene int değer atanırken 178 değeri 0x2b ye eşit olduğundan dönüşüm esnasında işaretini korumak için yüksek bitleri 1 yapacaktır. Bu yüzden c nin değeri 178 olmaz. `c` değişkeni `unsigned char` olsaydı standart outputta `dogru` çıktısını görürdük.

---
# 12.09.2024

## Arrays
