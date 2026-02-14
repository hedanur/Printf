*This project has been created as part of the 42 curriculum by hecakir .*

##  Tanım (Description)

Bu projenin temel amacı, C standart kütüphanesinde bulunan popüler `printf()` fonksiyonunu yeniden yazmaktır. Proje kapsamında, değişken sayıda argüman alan (**variadic functions**) yapılarının kullanımı ve karakter yönetimi üzerine derinlemesine bir deneyim kazanılmıştır. `ft_printf`, tampon yönetimi (buffer management) içermeyen ancak orijinal printf ile aynı çıktıları veren bir kütüphane olarak tasarlanmıştır.

##  Talimatlar (Instructions)

### Derleme (Compilation)
Proje, standart olarak `Wall`, `Wextra` ve `Werror` bayrakları ile derlenmelidir.
Bu kütüphaneyi derlemek ve yönetmek için terminalinizde aşağıdaki `make` komutlarını kullanabilirsiniz:

### Komut Listesi (Command List)

| Komut | İşlem | Açıklama |
| --- | --- | --- |
| `make`  | **Zorunlu** fonksiyonları derler ve `libft.a` arşivini oluşturur. |
| `make clean`  | Derleme sonrası oluşan gereksiz nesne dosyalarını (`.o`) temizler. |
| `make fclean`  | Tüm nesne dosyalarını ve oluşturulan `libft.a` dosyasını **tamamen siler**. |
| `make re` | Temiz bir başlangıç için her şeyi siler ve **baştan derler** (`fclean` + `make`). |

---

### Kullanım (Usage)

Kendi projenizde kullanmak için başlık dosyasını dahil edin ve derleme sırasında oluşturduğunuz `.a` dosyasını bağlayın:

```c
#include "ft_printf.h"
```

##  Teknik Özellikler (Technical Specifications)

Fonksiyon, aşağıdaki dönüşüm belirteçlerini (conversions) desteklemektedir:

| Belirteç | Açıklama |
| --- | --- |
| `%c` | Tek bir karakter yazdırır.

 |
| `%s` | Bir karakter dizisi (string) yazdırır.

 |
| `%p` | <br>`void *` işaretçisini hexadecimal formatta yazdırır.

 |
| `%d` / `%i` | Tam sayıları (base 10) yazdırır.

 |
| `%u` | İşaretsiz (unsigned) onluk sayıları yazdırır.

 |
| `%x` | Küçük harf hexadecimal sayıları yazdırır.

 |
| `%X` | Büyük harf hexadecimal sayıları yazdırır.

 |
| `%%` | Yüzde işaretini yazdırır.

---

## Variadic Fonksiyonlar

`ft_printf` projesinin temelinde, kaç tane argüman alacağı önceden bilinmeyen fonksiyonları yönetmemizi sağlayan **Variadic Functions** yapısı yer alır. Bu yapı `<stdarg.h>` kütüphanesini kullanır.

###  Temel Araçlar

| Function | Description |
| --- | --- |
| `va_list` | Argümanları tutacak olan özel bir veri tipi (bir işaretçi gibi düşünebilirsiniz). |
| `va_start` | `va_list`'i başlatır ve ilk değişken argümanın konumunu belirler. |
| `va_arg` | Sıradaki argümanı okur ve belirtilen veri tipine (int, char*, vb.) dönüştürür. |
| `va_end` | Argüman listesiyle işimiz bittiğinde temizlik yapar, belleği serbest bırakır. |
| `va_copy` | Bir `va_list` kopyası oluşturur (aynı listeyi iki kez dönmek gerekirse kullanılır). |

###  Nasıl Çalışır?

1. **Declaration:** Fonksiyon, sabit bir parametreden sonra `...` (ellipsis) ile tanımlanır.
```c
int ft_printf(const char *format, ...);
```
2. **Initialization:** `va_start` çağrılarak bilgisayara "Sabit olan `format` parametresinden hemen sonra gelen değerlere bakmaya başla" denir.
3. **Accessing:** `va_arg` her çağrıldığında listedeki bir sonraki elemanı çeker. Burada verinin tipini (örneğin `%d` için `int`) manuel olarak belirtmemiz gerekir.
4. **Cleanup:** Fonksiyon bitmeden önce `va_end` ile liste kapatılır. Bu, programın çökmesini veya bellek sızıntısını önlemek için zorunludur.

> **Note:** Variadic fonksiyonlarda `char` ve `short` gibi küçük tipler otomatik olarak `int`'e, `float` ise `double`'a yükseltilir (Default Argument Promotions). Bu yüzden `va_arg` içinde küçük tipleri çekerken dikkatli olunmalıdır.

---

### `Write`

Proje gereksinimlerine göre, standart `printf` kullanmak yerine tüm çıktıları sistem çağrısı olan `write` ile yönetiyoruz. Bu, hem tampon (buffer) yönetimini öğrenmemizi hem de düşük seviyeli (low-level) programlama mantığını kavramamızı sağlar.


##  Algoritma ve Veri Yapısı (Algorithm and Data Structure)

Proje, **recursive (özyinelemeli)** bir yapı ve **variadic macros** (`va_start`, `va_arg`, `va_end`) üzerine inşa edilmiştir.

1. **Parsing:** Format dizisi taranır, `%` karakteri görüldüğünde bir sonraki karakter `ft_format` fonksiyonuna gönderilir.
2. **Conversion:** İlgili belirteç tespit edildikten sonra `va_arg` kullanılarak argüman listesinden veri çekilir.
3. **Recursion:** Özellikle sayısal dönüşümlerde (`ft_decimal`, `ft_hex`, `ft_unsigned`), sayının basamaklarını doğru sırayla yazdırmak için özyinelemeli fonksiyonlar tercih edilmiştir.
4.
**Error Handling:** Her `write` işlemi kontrol edilir; herhangi bir hata durumunda fonksiyon `-1` döndürerek güvenli çıkış yapar.


## Kaynaklar ve Yapay Zeka Kullanımı (Resources and AI Usage)
* **Değişken Sayılı Fonksiyonlar Dokümantasyonu:** `stdarg.h` kütüphanesinin kullanımı üzerine resmi dökümanlar incelenmiştir.

* **Yapay Zeka Kullanımı:** Projenin mantıksal kurgusu ve hata ayıklama süreçlerinde AI araçlarından destek alınmıştır.  Özellikle:

`va_list` yapısının işleyiş mantığının kavranması.

`README.md` dosyasının subject kurallarına göre yapılandırılması.
