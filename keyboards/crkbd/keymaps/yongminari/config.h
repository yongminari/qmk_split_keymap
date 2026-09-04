#pragma once

/* Tap-Hold 판정: 다른 키 입력에 영향받지 않고 누른 시간만 사용 */
#define TAPPING_TERM 200
#define THUMB_TAPPING_TERM 175
#define TAPPING_TERM_PER_KEY

/* 연속 탭 후 같은 키를 다시 누르고 있으면 탭 문자를 반복 */
#define QUICK_TAP_TERM 175

/* Combo 설정 */
#define COMBO_TERM 200

/* Corne v4.1은 GP13(USB_VBUS_PIN)으로 USB 연결 쪽을 하드웨어 감지합니다. */
/* SPLIT_USB_DETECT를 켜면 콜드 부팅 중 양쪽이 slave로 오판정할 수 있습니다. */
#define MASTER_LEFT

/* RGB Matrix 설정 */
#ifdef RGB_MATRIX_ENABLE
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE // 누른 키 주변까지 불빛이 퍼지는 효과
#    define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
#    define RGB_MATRIX_DEFAULT_HUE 0
#    define RGB_MATRIX_DEFAULT_SAT 0   // 0이면 흰색에 가까움, 255면 원색
#    define RGB_MATRIX_DEFAULT_VAL 150 // 기본 밝기
#    undef RGB_MATRIX_MAXIMUM_BRIGHTNESS
#    define RGB_MATRIX_MAXIMUM_BRIGHTNESS 150 // 최대 밝기 제한
#    define RGB_MATRIX_LED_FLUSH_LIMIT 16
#    define RGB_MATRIX_KEYPRESSES // 키 누름에 반응하도록 설정
#    define RGB_MATRIX_TIMEOUT 30000 // 30초 후 LED 끄기
#endif
