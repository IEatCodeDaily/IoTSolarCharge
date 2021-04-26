/*
* Pustaka interval waktu
* Mekanisme membuat event waktu sederhana,
*/


// konstanta periode tak hingga
#define IP_INFINITE 0
// interval memerlukan 2 variabel
// sehingga dipakai struktur data struct
struct interval {
 long periode; // periode interval
 long timeout; // waktu akan terpicu
};

/*
* Inisialisasi interval dengan lama periode tertentu dalam ms
* Agar struct dapat dioleh dalam fungsi,
* maka parameter memakai tanda &, artinya reference ke variabel tersebut
* perhatikan cara menulisnya: struct interval &parameter.
* Selanjutnya field struct diakses pakai nama_variabel.nama_field
*/

void intervalInit(struct interval &itv, long ms) {
 itv.periode = ms; // simpan periode ke itv
 itv.timeout = millis()+ms; // siapkan waktu timeout = sekarang + periode
}
/*
* memajukan waktu interval berdasar timeout sebelumnya
*/
void intervalReset(struct interval &itv, long ms) {
 // hitung dulu waktu timeout terakhir,
 long before = itv.timeout-itv.periode;
 // timeout baru
 itv.timeout = before+ms;
 // simpan periode baru
 itv.periode = ms;
}

/*
* memeriksa apakah timeout sudah terjadi
* jika ya, timeout time akan ditambah periode untuk interval berikutnya
* lalu return true
*/

boolean isTimeout(struct interval &itv) {
 // kalau periode belum di-set, langsung return false
 if (itv.periode == IP_INFINITE) return false;
 // kalau waktu picu belum sampai, return false juga
 if (itv.timeout > millis()) return false;

 // ok, sudah waktu picu
 // siapkan dulu waktu picu berikutnya
 itv.timeout += itv.periode;
 // return true, karena event sudah terjadi
 return true;
}
