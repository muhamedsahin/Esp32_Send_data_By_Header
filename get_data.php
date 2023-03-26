<?php
$data = isset($_POST['POSTData']) ? $_POST['POSTData'] : '';

if ($data !== '') {
    $file = fopen('img/data.txt', 'w');
    if ($file) {
        if (fwrite($file, $data) !== false) {
            echo "Veri başarıyla dosyaya yazıldı: $data";
        } else {
            echo "Hata: Veri dosyaya yazılamadı";
        }
        fclose($file);
    } else {
        echo "Hata: Dosya açılamadı";
    }
} else {
    echo "Hata: POST verisi alınamadı";
}
?>
