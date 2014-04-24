
#include <stdint.h>
#include "guiGraphHAL.h"
#include "global_def.h"

#ifdef __cplusplus
extern "C" {
#endif

// Temporary display buffer, used for splitting GUI buffer into two separate LCD's
//#define DISPLAY_XSIZE 96
#define DISPLAY_XSIZE (LCD_XSIZE / 2)
//#define DISPLAY_YSIZE 68
#define DISPLAY_YSIZE LCD_YSIZE
//#define DISPLAY_BUFFER_SIZE 96*9
#define DISPLAY_BUFFER_SIZE (LCD_BUFFER_SIZE / 2)




//-----------------------------------//
// Callbacks
#define LOG_FROM_TOP      10
#define LOG_FROM_BOTTOM   11

typedef void (*cbLogPtr)(int type, char *string);
typedef void (*cbLcdUpdatePtr)(int displayNum, void *buffer);

void registerLogCallback(cbLogPtr fptr);
void registerLcdUpdateCallback(cbLcdUpdatePtr fptr);
//-----------------------------------//





// Functions for top-level
void guiInitialize(void);
void guiUpdateTime(uint8_t hours, uint8_t minutes, uint8_t seconds);
void guiDrawAll(void);

void guiButtonEvent(uint16_t buttonCode, uint8_t eventType);
//void guiButtonPressed(uint16_t buttonCode);
//void guiButtonReleased(uint16_t buttonCode);
void guiEncoderRotated(int32_t delta);


// Functions for calling from GUI
void guiLogEvent(char *string);




//=================================================================//
//=================================================================//
//                      Hardware emulation interface               //
//=================================================================//

typedef struct {
    uint32_t type;
    union {
        struct {
            uint32_t a;
            uint32_t b;
        } data;
        struct {
            uint8_t limit;
            uint8_t enable;
            uint32_t value;
        } voltage_limit_setting;
    };
    //	uint32_t data_a;
    //	uint32_t data_b;
} conveter_message_t;



// SelectedChannel
#define	GUI_CHANNEL_5V			0x1
#define	GUI_CHANNEL_12V			0x0
// CurrentLimit
#define	GUI_CURRENT_RANGE_HIGH	0x1
#define	GUI_CURRENT_RANGE_LOW	 	0x0
// Software limit types
#define GUI_LIMIT_TYPE_LOW			0x00
#define GUI_LIMIT_TYPE_HIGH			0x01



uint16_t getVoltageSetting(uint8_t channel);
uint16_t getVoltageAbsMax(uint8_t channel);
uint16_t getVoltageAbsMin(uint8_t channel);
uint16_t getVoltageLimitSetting(uint8_t channel, uint8_t limit_type);
uint8_t getVoltageLimitState(uint8_t channel, uint8_t limit_type);
uint16_t getCurrentSetting(uint8_t channel, uint8_t range);
uint16_t getCurrentAbsMax(uint8_t channel, uint8_t range);
uint16_t getCurrentAbsMin(uint8_t channel, uint8_t range);
uint16_t getCurrentLimitSetting(uint8_t channel, uint8_t range, uint8_t limit_type);
uint8_t getCurrentLimitState(uint8_t channel, uint8_t range, uint8_t limit_type);
uint8_t getOverloadProtectionState(void);
uint8_t getOverloadProtectionWarning(void);
uint16_t getOverloadProtectionThreshold(void);
uint8_t getCurrentRange(uint8_t channel);

uint8_t BTN_IsExtSwitchEnabled(void);
uint8_t BTN_GetExtSwitchInversion(void);
uint8_t BTN_GetExtSwitchMode(void);




#define taskENTER_CRITICAL() ;
#define taskEXIT_CRITICAL() ;




void guiUpdateChannelSetting(void);
void applyGuiChannelSetting(uint8_t new_channel);








void guiTop_UpdateGuiVoltageIndicator(void);
void guiTop_UpdateCurrentIndicator(void);
void guiTop_UpdatePowerIndicator(void);
void guiTop_UpdateTemperatureIndicator(void);

void guiTop_ApplyGuiVoltageSetting(uint8_t channel, int16_t new_set_voltage);
void guiTop_UpdateVoltageSetting(uint8_t channel);

void guiTop_ApplyCurrentSetting(uint8_t channel, uint8_t currentRange, int16_t new_set_current);
void guiTop_UpdateCurrentSetting(uint8_t channel, uint8_t currentRange);

void guiTop_ApplyGuiVoltageLimit(uint8_t channel, uint8_t limit_type, uint8_t enable, int16_t value);
void guiTop_ApplyGuiCurrentLimit(uint8_t channel, uint8_t currentRange, uint8_t limit_type, uint8_t enable, int16_t value);
void guiTop_UpdateVoltageLimit(uint8_t channel, uint8_t limit_type);
void guiTop_UpdateCurrentLimit(uint8_t channel, uint8_t range, uint8_t limit_type);

void guiTop_ApplyCurrentRange(uint8_t channel, uint8_t new_current_range);
void guiTop_UpdateCurrentRange(uint8_t channel);

void guiTop_ApplyGuiOverloadSettings(uint8_t protectionEnable, uint8_t warningEnable, int32_t newThreshold);
void guiTop_UpdateOverloadSettings(void);

void guiTop_ApplyGuiProfileSettings(uint8_t saveRecentProfile, uint8_t restoreRecentProfile);
void guiTop_UpdateProfileSettings(void);
void guiTop_LoadProfile(uint8_t index);
void guiTop_SaveProfile(uint8_t index, char *profileName);

void guiTop_ApplyExtSwitchSettings(uint8_t enable, uint8_t inverse, uint8_t mode);
void guiTop_UpdateExtSwitchSettings(void);

void guiTop_ApplyDacSettings(int8_t v_offset, int8_t c_low_offset, int8_t c_high_offset);
void guiTop_UpdateDacSettings(void);

uint8_t readProfileListRecordName(uint8_t index, char *profileName);

#ifdef __cplusplus
}
#endif
