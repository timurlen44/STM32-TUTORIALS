#include "main.h"
#include "stdbool.h"
#include "string.h"
#define NODE_ID 10 // Default NodeID is 10
enum FIR_Filter_Hz_Enum{_FIR_Deactivated = 0, _FIR_Ten_Hz = 1, _FIR_Five_Hz = 2, _FIR_One_Hz = 3, _FIR_Half_Hz = 4};

struct jn2101_struct
{
	uint8_t Node_ID;
	uint16_t Baud_Rate;
	uint8_t Is_Device_Connected;
	uint32_t Vendor_ID;
	uint32_t Product_Code;
	uint32_t Revision_Number;
	uint32_t Serial_Number;
	enum FIR_Filter_Hz_Enum FIR_Filter_Hz;

	int16_t x_axis_raw;
	int16_t y_axis_raw;
	double x_axis_degree;
	double y_axis_degree;
	double filtered_x_axis_degree;
	double filtered_y_axis_degree;

}jn2101;






uint8_t send_data_to_jn2101[8];
uint8_t received_data_from_jn2101[8];

CAN_RxHeaderTypeDef RxReceiver;
CAN_TxHeaderTypeDef TxTransmitter;
uint32_t MailBox;
void init_jn2101_lib();
void read_jn2101_node_id();
void read_jn2101_canbus_baudrate();
void is_jn2101_connected();

void read_jn2101_vendor_id();
void read_jn2101_product_code();
void read_jn2101_revision_number();
void read_jn2101_serial_number();
void read_flag_for_quadrant_correction();
void read_jn2101_x_axis();
void read_jn2101_y_axis();

void read_jn2101_FIR_filter_hz();
void set_jn2101_FIR_filter_hz(enum FIR_Filter_Hz_Enum FIR_Filter_Hz);

