
#define PP_ON			(0xC7208)
#define PP_OFF			(0xC720C)
#define PP_DIVISOR 		(0xC7210)
#define PP_STATUS		(0xC7200)
#define PP_CONTROL		(0xC7204)
//#define BUILD_BUG_ON_ZERO(e) ((int)(sizeof(struct { int:(-!!(e)); })))

/*
 * Local integer constant expression version of is_power_of_2().
 */
#define IS_POWER_OF_2(__x)		((__x) && (((__x) & ((__x) - 1)) == 0))

/**
 * REG_FIELD_PREP() - Prepare a u32 bitfield value
 * @__mask: shifted mask defining the field's length and position
 * @__val: value to put in the field
 *
 * Local copy of FIELD_PREP() to generate an integer constant expression, force
 * u32 and for consistency with REG_FIELD_GET(), REG_BIT() and REG_GENMASK().
 *
 * @return: @__val masked and shifted into the field defined by @__mask.
 */
#define REG_FIELD_PREP(__mask, __val)						\
	((UINT32)((((typeof(__mask))(__val) << __bf_shf(__mask)) & (__mask)) +	\
	       (!__is_constexpr(__mask)) +		\
	       ((__mask) == 0 || (__mask) > __UINT32_MAX__) +		\
	       (!IS_POWER_OF_2((__mask) + (1ULL << __bf_shf(__mask)))) + \
	       (__builtin_choose_expr(__is_constexpr(__val), (~((__mask) >> __bf_shf(__mask)) & (__val)), 0))))
#define _PCH_DP_B        (0xe4100)
#define _PCH_DPB_AUX_CH_CTL    (0xe4110)
#define _PCH_DPB_AUX_CH_DATA1    (0xe4114)
#define _PCH_DPB_AUX_CH_DATA2    (0xe4118)
#define _PCH_DPB_AUX_CH_DATA3    (0xe411c)
#define _PCH_DPB_AUX_CH_DATA4    (0xe4120)
#define _PCH_DPB_AUX_CH_DATA5    (0xe4124)

#define _DPA_AUX_CH_CTL        (0x64010)
#define _DPA_AUX_CH_DATA1    (0x64014)
#define _DPA_AUX_CH_DATA2    (0x64018)
#define _DPA_AUX_CH_DATA3    (0x6401c)
#define _DPA_AUX_CH_DATA4    (0x64020)
#define _DPA_AUX_CH_DATA5    (0x64024)

#define   DP_AUX_CH_CTL_SEND_BUSY        (1 << 31)
#define   DP_AUX_CH_CTL_DONE            (1 << 30)
#define   DP_AUX_CH_CTL_INTERRUPT        (1 << 29)
#define   DP_AUX_CH_CTL_TIME_OUT_ERROR        (1 << 28)
#define   DP_AUX_CH_CTL_TIME_OUT_400us        (0 << 26)
#define   DP_AUX_CH_CTL_TIME_OUT_600us        (1 << 26)
#define   DP_AUX_CH_CTL_TIME_OUT_800us        (2 << 26)
#define   DP_AUX_CH_CTL_TIME_OUT_MAX        (3 << 26) /* Varies per platform */
#define   DP_AUX_CH_CTL_TIME_OUT_MASK        (3 << 26)
#define   DP_AUX_CH_CTL_RECEIVE_ERROR        (1 << 25)
#define   DP_AUX_CH_CTL_MESSAGE_SIZE_MASK    (0x1f << 20)
#define   DP_AUX_CH_CTL_MESSAGE_SIZE_SHIFT   20
#define   DP_AUX_CH_CTL_PRECHARGE_2US_MASK   (0xf << 16)
#define   DP_AUX_CH_CTL_PRECHARGE_2US_SHIFT  16
#define   DP_AUX_CH_CTL_AUX_AKSV_SELECT        (1 << 15)
#define   DP_AUX_CH_CTL_MANCHESTER_TEST        (1 << 14)
#define   DP_AUX_CH_CTL_SYNC_TEST        (1 << 13)
#define   DP_AUX_CH_CTL_DEGLITCH_TEST        (1 << 12)
#define   DP_AUX_CH_CTL_PRECHARGE_TEST        (1 << 11)
#define   DP_AUX_CH_CTL_BIT_CLOCK_2X_MASK    (0x7ff)
#define   DP_AUX_CH_CTL_BIT_CLOCK_2X_SHIFT   0
#define   DP_AUX_CH_CTL_PSR_DATA_AUX_REG_SKL    (1 << 14)
#define   DP_AUX_CH_CTL_FS_DATA_AUX_REG_SKL    (1 << 13)
#define   DP_AUX_CH_CTL_GTC_DATA_AUX_REG_SKL    (1 << 12)
#define   DP_AUX_CH_CTL_TBT_IO            (1 << 11)
#define   DP_AUX_CH_CTL_FW_SYNC_PULSE_SKL_MASK (0x1f << 5)
#define   DP_AUX_CH_CTL_FW_SYNC_PULSE_SKL(c) (((c) - 1) << 5)
#define   DP_AUX_CH_CTL_SYNC_PULSE_SKL(c)   ((c) - 1)
#define AUX_NATIVE_WRITE            0x8
#define AUX_NATIVE_READ            0x9
#define AUX_I2C_WRITE            0x0
#define AUX_I2C_READ            0x1
#define AUX_I2C_STATUS            0x2
#define AUX_I2C_MOT                0x4
#define AUX_I2C_REPLY_ACK            0x0
/* DisplayPort Transport Control */
#define _DP_TP_CTL_A			0x64040
#define _DP_TP_CTL_B			0x64140
#define _TGL_DP_TP_CTL_A		0x60540
#define DP_TP_CTL(port) _PORT(port, _DP_TP_CTL_A, _DP_TP_CTL_B)
// #define TGL_DP_TP_CTL(tran) _MMIO_TRANS2((tran), _TGL_DP_TP_CTL_A)
#define  DP_TP_CTL_ENABLE			(1 << 31)
#define  DP_TP_CTL_FEC_ENABLE			(1 << 30)
#define  DP_TP_CTL_MODE_SST			(0 << 27)
#define  DP_TP_CTL_MODE_MST			(1 << 27)
#define  DP_TP_CTL_FORCE_ACT			(1 << 25)
#define  DP_TP_CTL_ENHANCED_FRAME_ENABLE	(1 << 18)
#define  DP_TP_CTL_FDI_AUTOTRAIN		(1 << 15)
#define  DP_TP_CTL_LINK_TRAIN_MASK		(7 << 8)
#define  DP_TP_CTL_LINK_TRAIN_PAT1		(0 << 8)
#define  DP_TP_CTL_LINK_TRAIN_PAT2		(1 << 8)
#define  DP_TP_CTL_LINK_TRAIN_PAT3		(4 << 8)
#define  DP_TP_CTL_LINK_TRAIN_PAT4		(5 << 8)
#define  DP_TP_CTL_LINK_TRAIN_IDLE		(2 << 8)
#define  DP_TP_CTL_LINK_TRAIN_NORMAL		(3 << 8)
#define  DP_TP_CTL_SCRAMBLE_DISABLE		(1 << 7)
#define DP_MSA_MISC_SYNC_CLOCK			(1 << 0)
#define DP_MSA_MISC_INTERLACE_VTOTAL_EVEN	(1 << 8)
#define DP_MSA_MISC_STEREO_NO_3D		(0 << 9)
#define DP_MSA_MISC_STEREO_PROG_RIGHT_EYE	(1 << 9)
#define DP_MSA_MISC_STEREO_PROG_LEFT_EYE	(3 << 9)
/* bits per component for non-RAW */
#define DP_MSA_MISC_6_BPC			(0 << 5)
#define DP_MSA_MISC_8_BPC			(1 << 5)
#define DP_MSA_MISC_10_BPC			(2 << 5)
#define DP_MSA_MISC_12_BPC			(3 << 5)
#define DP_MSA_MISC_16_BPC			(4 << 5)
/* bits per component for RAW */
#define DP_MSA_MISC_RAW_6_BPC			(1 << 5)
#define DP_MSA_MISC_RAW_7_BPC			(2 << 5)
#define DP_MSA_MISC_RAW_8_BPC			(3 << 5)
#define DP_MSA_MISC_RAW_10_BPC			(4 << 5)
#define DP_MSA_MISC_RAW_12_BPC			(5 << 5)
#define DP_MSA_MISC_RAW_14_BPC			(6 << 5)
#define DP_MSA_MISC_RAW_16_BPC			(7 << 5)
/* pixel encoding/colorimetry format */
#define _DP_MSA_MISC_COLOR(misc1_7, misc0_21, misc0_3, misc0_4) \
	((misc1_7) << 15 | (misc0_4) << 4 | (misc0_3) << 3 | ((misc0_21) << 1))
#define DP_MSA_MISC_COLOR_RGB			_DP_MSA_MISC_COLOR(0, 0, 0, 0)
#define DP_MSA_MISC_COLOR_CEA_RGB		_DP_MSA_MISC_COLOR(0, 0, 1, 0)
#define DP_MSA_MISC_COLOR_RGB_WIDE_FIXED	_DP_MSA_MISC_COLOR(0, 3, 0, 0)
#define DP_MSA_MISC_COLOR_RGB_WIDE_FLOAT	_DP_MSA_MISC_COLOR(0, 3, 0, 1)
#define DP_MSA_MISC_COLOR_Y_ONLY		_DP_MSA_MISC_COLOR(1, 0, 0, 0)
#define DP_MSA_MISC_COLOR_RAW			_DP_MSA_MISC_COLOR(1, 1, 0, 0)
#define DP_MSA_MISC_COLOR_YCBCR_422_BT601	_DP_MSA_MISC_COLOR(0, 1, 1, 0)
#define DP_MSA_MISC_COLOR_YCBCR_422_BT709	_DP_MSA_MISC_COLOR(0, 1, 1, 1)
#define DP_MSA_MISC_COLOR_YCBCR_444_BT601	_DP_MSA_MISC_COLOR(0, 2, 1, 0)
#define DP_MSA_MISC_COLOR_YCBCR_444_BT709	_DP_MSA_MISC_COLOR(0, 2, 1, 1)
#define DP_MSA_MISC_COLOR_XVYCC_422_BT601	_DP_MSA_MISC_COLOR(0, 1, 0, 0)
#define DP_MSA_MISC_COLOR_XVYCC_422_BT709	_DP_MSA_MISC_COLOR(0, 1, 0, 1)
#define DP_MSA_MISC_COLOR_XVYCC_444_BT601	_DP_MSA_MISC_COLOR(0, 2, 0, 0)
#define DP_MSA_MISC_COLOR_XVYCC_444_BT709	_DP_MSA_MISC_COLOR(0, 2, 0, 1)
#define DP_MSA_MISC_COLOR_OPRGB			_DP_MSA_MISC_COLOR(0, 0, 1, 1)
#define DP_MSA_MISC_COLOR_DCI_P3		_DP_MSA_MISC_COLOR(0, 3, 1, 0)
#define DP_MSA_MISC_COLOR_COLOR_PROFILE		_DP_MSA_MISC_COLOR(0, 3, 1, 1)
#define DP_MSA_MISC_COLOR_VSC_SDP		(1 << 14)

#define DP_AUX_MAX_PAYLOAD_BYTES	16

#define DP_AUX_I2C_WRITE		0x0
#define DP_AUX_I2C_READ			0x1
#define DP_AUX_I2C_WRITE_STATUS_UPDATE	0x2
#define DP_AUX_I2C_MOT			0x4
#define DP_AUX_NATIVE_WRITE		0x8
#define DP_AUX_NATIVE_READ		0x9

#define DP_AUX_NATIVE_REPLY_ACK		(0x0 << 0)
#define DP_AUX_NATIVE_REPLY_NACK	(0x1 << 0)
#define DP_AUX_NATIVE_REPLY_DEFER	(0x2 << 0)
#define DP_AUX_NATIVE_REPLY_MASK	(0x3 << 0)

#define DP_AUX_I2C_REPLY_ACK		(0x0 << 2)
#define DP_AUX_I2C_REPLY_NACK		(0x1 << 2)
#define DP_AUX_I2C_REPLY_DEFER		(0x2 << 2)
#define DP_AUX_I2C_REPLY_MASK		(0x3 << 2)

/* AUX CH addresses */
/* DPCD */
#define DP_DPCD_REV                         0x000
# define DP_DPCD_REV_10                     0x10
# define DP_DPCD_REV_11                     0x11
# define DP_DPCD_REV_12                     0x12
# define DP_DPCD_REV_13                     0x13
# define DP_DPCD_REV_14                     0x14

#define DP_MAX_LINK_RATE                    0x001

#define DP_MAX_LANE_COUNT                   0x002
# define DP_MAX_LANE_COUNT_MASK		    0x1f
# define DP_TPS3_SUPPORTED		    (1 << 6) /* 1.2 */
# define DP_ENHANCED_FRAME_CAP		    (1 << 7)

#define DP_MAX_DOWNSPREAD                   0x003
# define DP_MAX_DOWNSPREAD_0_5		    (1 << 0)
# define DP_NO_AUX_HANDSHAKE_LINK_TRAINING  (1 << 6)
# define DP_TPS4_SUPPORTED                  (1 << 7)

#define DP_NORP                             0x004

#define DP_DOWNSTREAMPORT_PRESENT           0x005
# define DP_DWN_STRM_PORT_PRESENT           (1 << 0)
# define DP_DWN_STRM_PORT_TYPE_MASK         0x06
# define DP_DWN_STRM_PORT_TYPE_DP           (0 << 1)
# define DP_DWN_STRM_PORT_TYPE_ANALOG       (1 << 1)
# define DP_DWN_STRM_PORT_TYPE_TMDS         (2 << 1)
# define DP_DWN_STRM_PORT_TYPE_OTHER        (3 << 1)
# define DP_FORMAT_CONVERSION               (1 << 3)
# define DP_DETAILED_CAP_INFO_AVAILABLE	    (1 << 4) /* DPI */

#define DP_MAIN_LINK_CHANNEL_CODING         0x006
# define DP_CAP_ANSI_8B10B		    (1 << 0)

#define DP_DOWN_STREAM_PORT_COUNT	    0x007
# define DP_PORT_COUNT_MASK		    0x0f
# define DP_MSA_TIMING_PAR_IGNORED	    (1 << 6) /* eDP */
# define DP_OUI_SUPPORT			    (1 << 7)

#define DP_RECEIVE_PORT_0_CAP_0		    0x008
# define DP_LOCAL_EDID_PRESENT		    (1 << 1)
# define DP_ASSOCIATED_TO_PRECEDING_PORT    (1 << 2)

#define DP_RECEIVE_PORT_0_BUFFER_SIZE	    0x009

#define DP_RECEIVE_PORT_1_CAP_0		    0x00a
#define DP_RECEIVE_PORT_1_BUFFER_SIZE       0x00b

#define DP_I2C_SPEED_CAP		    0x00c    /* DPI */
# define DP_I2C_SPEED_1K		    0x01
# define DP_I2C_SPEED_5K		    0x02
# define DP_I2C_SPEED_10K		    0x04
# define DP_I2C_SPEED_100K		    0x08
# define DP_I2C_SPEED_400K		    0x10
# define DP_I2C_SPEED_1M		    0x20

#define DP_EDP_CONFIGURATION_CAP            0x00d   /* XXX 1.2? */
# define DP_ALTERNATE_SCRAMBLER_RESET_CAP   (1 << 0)
# define DP_FRAMING_CHANGE_CAP		    (1 << 1)
# define DP_DPCD_DISPLAY_CONTROL_CAPABLE     (1 << 3) /* edp v1.2 or higher */

#define DP_TRAINING_AUX_RD_INTERVAL             0x00e   /* XXX 1.2? */
# define DP_TRAINING_AUX_RD_MASK                0x7F    /* DP 1.3 */
# define DP_EXTENDED_RECEIVER_CAP_FIELD_PRESENT	(1 << 7) /* DP 1.3 */

#define DP_ADAPTER_CAP			    0x00f   /* 1.2 */
# define DP_FORCE_LOAD_SENSE_CAP	    (1 << 0)
# define DP_ALTERNATE_I2C_PATTERN_CAP	    (1 << 1)

#define DP_SUPPORTED_LINK_RATES		    0x010 /* eDP 1.4 */
# define DP_MAX_SUPPORTED_RATES		     8	    /* 16-bit little-endian */

/* Multiple stream transport */
#define DP_FAUX_CAP			    0x020   /* 1.2 */
# define DP_FAUX_CAP_1			    (1 << 0)

#define DP_MSTM_CAP			    0x021   /* 1.2 */
# define DP_MST_CAP			    (1 << 0)

#define DP_NUMBER_OF_AUDIO_ENDPOINTS	    0x022   /* 1.2 */

/* AV_SYNC_DATA_BLOCK                                  1.2 */
#define DP_AV_GRANULARITY		    0x023
# define DP_AG_FACTOR_MASK		    (0xf << 0)
# define DP_AG_FACTOR_3MS		    (0 << 0)
# define DP_AG_FACTOR_2MS		    (1 << 0)
# define DP_AG_FACTOR_1MS		    (2 << 0)
# define DP_AG_FACTOR_500US		    (3 << 0)
# define DP_AG_FACTOR_200US		    (4 << 0)
# define DP_AG_FACTOR_100US		    (5 << 0)
# define DP_AG_FACTOR_10US		    (6 << 0)
# define DP_AG_FACTOR_1US		    (7 << 0)
# define DP_VG_FACTOR_MASK		    (0xf << 4)
# define DP_VG_FACTOR_3MS		    (0 << 4)
# define DP_VG_FACTOR_2MS		    (1 << 4)
# define DP_VG_FACTOR_1MS		    (2 << 4)
# define DP_VG_FACTOR_500US		    (3 << 4)
# define DP_VG_FACTOR_200US		    (4 << 4)
# define DP_VG_FACTOR_100US		    (5 << 4)

#define DP_AUD_DEC_LAT0			    0x024
#define DP_AUD_DEC_LAT1			    0x025

#define DP_AUD_PP_LAT0			    0x026
#define DP_AUD_PP_LAT1			    0x027

#define DP_VID_INTER_LAT		    0x028

#define DP_VID_PROG_LAT			    0x029

#define DP_REP_LAT			    0x02a

#define DP_AUD_DEL_INS0			    0x02b
#define DP_AUD_DEL_INS1			    0x02c
#define DP_AUD_DEL_INS2			    0x02d
/* End of AV_SYNC_DATA_BLOCK */

#define DP_RECEIVER_ALPM_CAP		    0x02e   /* eDP 1.4 */
# define DP_ALPM_CAP			    (1 << 0)

#define DP_SINK_DEVICE_AUX_FRAME_SYNC_CAP   0x02f   /* eDP 1.4 */
# define DP_AUX_FRAME_SYNC_CAP		    (1 << 0)

#define DP_GUID				    0x030   /* 1.2 */

#define DP_DSC_SUPPORT                      0x060   /* DP 1.4 */
# define DP_DSC_DECOMPRESSION_IS_SUPPORTED  (1 << 0)

#define DP_DSC_REV                          0x061
# define DP_DSC_MAJOR_MASK                  (0xf << 0)
# define DP_DSC_MINOR_MASK                  (0xf << 4)
# define DP_DSC_MAJOR_SHIFT                 0
# define DP_DSC_MINOR_SHIFT                 4

#define DP_DSC_RC_BUF_BLK_SIZE              0x062
# define DP_DSC_RC_BUF_BLK_SIZE_1           0x0
# define DP_DSC_RC_BUF_BLK_SIZE_4           0x1
# define DP_DSC_RC_BUF_BLK_SIZE_16          0x2
# define DP_DSC_RC_BUF_BLK_SIZE_64          0x3

#define DP_DSC_RC_BUF_SIZE                  0x063

#define DP_DSC_SLICE_CAP_1                  0x064
# define DP_DSC_1_PER_DP_DSC_SINK           (1 << 0)
# define DP_DSC_2_PER_DP_DSC_SINK           (1 << 1)
# define DP_DSC_4_PER_DP_DSC_SINK           (1 << 3)
# define DP_DSC_6_PER_DP_DSC_SINK           (1 << 4)
# define DP_DSC_8_PER_DP_DSC_SINK           (1 << 5)
# define DP_DSC_10_PER_DP_DSC_SINK          (1 << 6)
# define DP_DSC_12_PER_DP_DSC_SINK          (1 << 7)

#define DP_DSC_LINE_BUF_BIT_DEPTH           0x065
# define DP_DSC_LINE_BUF_BIT_DEPTH_MASK     (0xf << 0)
# define DP_DSC_LINE_BUF_BIT_DEPTH_9        0x0
# define DP_DSC_LINE_BUF_BIT_DEPTH_10       0x1
# define DP_DSC_LINE_BUF_BIT_DEPTH_11       0x2
# define DP_DSC_LINE_BUF_BIT_DEPTH_12       0x3
# define DP_DSC_LINE_BUF_BIT_DEPTH_13       0x4
# define DP_DSC_LINE_BUF_BIT_DEPTH_14       0x5
# define DP_DSC_LINE_BUF_BIT_DEPTH_15       0x6
# define DP_DSC_LINE_BUF_BIT_DEPTH_16       0x7
# define DP_DSC_LINE_BUF_BIT_DEPTH_8        0x8

#define DP_DSC_BLK_PREDICTION_SUPPORT       0x066
# define DP_DSC_BLK_PREDICTION_IS_SUPPORTED (1 << 0)

#define DP_DSC_MAX_BITS_PER_PIXEL_LOW       0x067   /* eDP 1.4 */

#define DP_DSC_MAX_BITS_PER_PIXEL_HI        0x068   /* eDP 1.4 */
# define DP_DSC_MAX_BITS_PER_PIXEL_HI_MASK  (0x3 << 0)
# define DP_DSC_MAX_BITS_PER_PIXEL_HI_SHIFT 8

#define DP_DSC_DEC_COLOR_FORMAT_CAP         0x069
# define DP_DSC_RGB                         (1 << 0)
# define DP_DSC_YCbCr444                    (1 << 1)
# define DP_DSC_YCbCr422_Simple             (1 << 2)
# define DP_DSC_YCbCr422_Native             (1 << 3)
# define DP_DSC_YCbCr420_Native             (1 << 4)

#define DP_DSC_DEC_COLOR_DEPTH_CAP          0x06A
# define DP_DSC_8_BPC                       (1 << 1)
# define DP_DSC_10_BPC                      (1 << 2)
# define DP_DSC_12_BPC                      (1 << 3)

#define DP_DSC_PEAK_THROUGHPUT              0x06B
# define DP_DSC_THROUGHPUT_MODE_0_MASK      (0xf << 0)
# define DP_DSC_THROUGHPUT_MODE_0_SHIFT     0
# define DP_DSC_THROUGHPUT_MODE_0_UNSUPPORTED 0
# define DP_DSC_THROUGHPUT_MODE_0_340       (1 << 0)
# define DP_DSC_THROUGHPUT_MODE_0_400       (2 << 0)
# define DP_DSC_THROUGHPUT_MODE_0_450       (3 << 0)
# define DP_DSC_THROUGHPUT_MODE_0_500       (4 << 0)
# define DP_DSC_THROUGHPUT_MODE_0_550       (5 << 0)
# define DP_DSC_THROUGHPUT_MODE_0_600       (6 << 0)
# define DP_DSC_THROUGHPUT_MODE_0_650       (7 << 0)
# define DP_DSC_THROUGHPUT_MODE_0_700       (8 << 0)
# define DP_DSC_THROUGHPUT_MODE_0_750       (9 << 0)
# define DP_DSC_THROUGHPUT_MODE_0_800       (10 << 0)
# define DP_DSC_THROUGHPUT_MODE_0_850       (11 << 0)
# define DP_DSC_THROUGHPUT_MODE_0_900       (12 << 0)
# define DP_DSC_THROUGHPUT_MODE_0_950       (13 << 0)
# define DP_DSC_THROUGHPUT_MODE_0_1000      (14 << 0)
# define DP_DSC_THROUGHPUT_MODE_0_170       (15 << 0) /* 1.4a */
# define DP_DSC_THROUGHPUT_MODE_1_MASK      (0xf << 4)
# define DP_DSC_THROUGHPUT_MODE_1_SHIFT     4
# define DP_DSC_THROUGHPUT_MODE_1_UNSUPPORTED 0
# define DP_DSC_THROUGHPUT_MODE_1_340       (1 << 4)
# define DP_DSC_THROUGHPUT_MODE_1_400       (2 << 4)
# define DP_DSC_THROUGHPUT_MODE_1_450       (3 << 4)
# define DP_DSC_THROUGHPUT_MODE_1_500       (4 << 4)
# define DP_DSC_THROUGHPUT_MODE_1_550       (5 << 4)
# define DP_DSC_THROUGHPUT_MODE_1_600       (6 << 4)
# define DP_DSC_THROUGHPUT_MODE_1_650       (7 << 4)
# define DP_DSC_THROUGHPUT_MODE_1_700       (8 << 4)
# define DP_DSC_THROUGHPUT_MODE_1_750       (9 << 4)
# define DP_DSC_THROUGHPUT_MODE_1_800       (10 << 4)
# define DP_DSC_THROUGHPUT_MODE_1_850       (11 << 4)
# define DP_DSC_THROUGHPUT_MODE_1_900       (12 << 4)
# define DP_DSC_THROUGHPUT_MODE_1_950       (13 << 4)
# define DP_DSC_THROUGHPUT_MODE_1_1000      (14 << 4)
# define DP_DSC_THROUGHPUT_MODE_1_170       (15 << 4)

#define DP_DSC_MAX_SLICE_WIDTH              0x06C
#define DP_DSC_MIN_SLICE_WIDTH_VALUE        2560
#define DP_DSC_SLICE_WIDTH_MULTIPLIER       320

#define DP_DSC_SLICE_CAP_2                  0x06D
# define DP_DSC_16_PER_DP_DSC_SINK          (1 << 0)
# define DP_DSC_20_PER_DP_DSC_SINK          (1 << 1)
# define DP_DSC_24_PER_DP_DSC_SINK          (1 << 2)

#define DP_DSC_BITS_PER_PIXEL_INC           0x06F
# define DP_DSC_BITS_PER_PIXEL_1_16         0x0
# define DP_DSC_BITS_PER_PIXEL_1_8          0x1
# define DP_DSC_BITS_PER_PIXEL_1_4          0x2
# define DP_DSC_BITS_PER_PIXEL_1_2          0x3
# define DP_DSC_BITS_PER_PIXEL_1            0x4

#define DP_PSR_SUPPORT                      0x070   /* XXX 1.2? */
# define DP_PSR_IS_SUPPORTED                1
# define DP_PSR2_IS_SUPPORTED		    2	    /* eDP 1.4 */
# define DP_PSR2_WITH_Y_COORD_IS_SUPPORTED  3	    /* eDP 1.4a */

#define DP_PSR_CAPS                         0x071   /* XXX 1.2? */
# define DP_PSR_NO_TRAIN_ON_EXIT            1
# define DP_PSR_SETUP_TIME_330              (0 << 1)
# define DP_PSR_SETUP_TIME_275              (1 << 1)
# define DP_PSR_SETUP_TIME_220              (2 << 1)
# define DP_PSR_SETUP_TIME_165              (3 << 1)
# define DP_PSR_SETUP_TIME_110              (4 << 1)
# define DP_PSR_SETUP_TIME_55               (5 << 1)
# define DP_PSR_SETUP_TIME_0                (6 << 1)
# define DP_PSR_SETUP_TIME_MASK             (7 << 1)
# define DP_PSR_SETUP_TIME_SHIFT            1
# define DP_PSR2_SU_Y_COORDINATE_REQUIRED   (1 << 4)  /* eDP 1.4a */
# define DP_PSR2_SU_GRANULARITY_REQUIRED    (1 << 5)  /* eDP 1.4b */

#define DP_PSR2_SU_X_GRANULARITY	    0x072 /* eDP 1.4b */
#define DP_PSR2_SU_Y_GRANULARITY	    0x074 /* eDP 1.4b */

/*
 * 0x80-0x8f describe downstream port capabilities, but there are two layouts
 * based on whether DP_DETAILED_CAP_INFO_AVAILABLE was set.  If it was not,
 * each port's descriptor is one byte wide.  If it was set, each port's is
 * four bytes wide, starting with the one byte from the base info.  As of
 * DP interop v1.1a only VGA defines additional detail.
 */

/* offset 0 */
#define DP_DOWNSTREAM_PORT_0		    0x80
# define DP_DS_PORT_TYPE_MASK		    (7 << 0)
# define DP_DS_PORT_TYPE_DP		    0
# define DP_DS_PORT_TYPE_VGA		    1
# define DP_DS_PORT_TYPE_DVI		    2
# define DP_DS_PORT_TYPE_HDMI		    3
# define DP_DS_PORT_TYPE_NON_EDID	    4
# define DP_DS_PORT_TYPE_DP_DUALMODE        5
# define DP_DS_PORT_TYPE_WIRELESS           6
# define DP_DS_PORT_HPD			    (1 << 3)
/* offset 1 for VGA is maximum megapixels per second / 8 */
/* offset 2 */
# define DP_DS_MAX_BPC_MASK	            (3 << 0)
# define DP_DS_8BPC		            0
# define DP_DS_10BPC		            1
# define DP_DS_12BPC		            2
# define DP_DS_16BPC		            3

#define DP_MAX_DOWNSTREAM_PORTS		    0x10

/* DP Forward error Correction Registers */
#define DP_FEC_CAPABILITY		    0x090    /* 1.4 */
# define DP_FEC_CAPABLE			    (1 << 0)
# define DP_FEC_UNCORR_BLK_ERROR_COUNT_CAP  (1 << 1)
# define DP_FEC_CORR_BLK_ERROR_COUNT_CAP    (1 << 2)
# define DP_FEC_BIT_ERROR_COUNT_CAP	    (1 << 3)

/* DP Extended DSC Capabilities */
#define DP_DSC_BRANCH_OVERALL_THROUGHPUT_0  0x0a0   /* DP 1.4a SCR */
#define DP_DSC_BRANCH_OVERALL_THROUGHPUT_1  0x0a1
#define DP_DSC_BRANCH_MAX_LINE_WIDTH        0x0a2

/* link configuration */
#define	DP_LINK_BW_SET		            0x100
# define DP_LINK_RATE_TABLE		    0x00    /* eDP 1.4 */
# define DP_LINK_BW_1_62		    0x06
# define DP_LINK_BW_2_7			    0x0a
# define DP_LINK_BW_5_4			    0x14    /* 1.2 */
# define DP_LINK_BW_8_1			    0x1e    /* 1.4 */

#define DP_LANE_COUNT_SET	            0x101
# define DP_LANE_COUNT_MASK		    0x0f
# define DP_LANE_COUNT_ENHANCED_FRAME_EN    (1 << 7)

#define DP_TRAINING_PATTERN_SET	            0x102
# define DP_TRAINING_PATTERN_DISABLE	    0
# define DP_TRAINING_PATTERN_1		    1
# define DP_TRAINING_PATTERN_2		    2
# define DP_TRAINING_PATTERN_3		    3	    /* 1.2 */
# define DP_TRAINING_PATTERN_4              7       /* 1.4 */
# define DP_TRAINING_PATTERN_MASK	    0x3
# define DP_TRAINING_PATTERN_MASK_1_4	    0xf

/* DPCD 1.1 only. For DPCD >= 1.2 see per-lane DP_LINK_QUAL_LANEn_SET */
# define DP_LINK_QUAL_PATTERN_11_DISABLE    (0 << 2)
# define DP_LINK_QUAL_PATTERN_11_D10_2	    (1 << 2)
# define DP_LINK_QUAL_PATTERN_11_ERROR_RATE (2 << 2)
# define DP_LINK_QUAL_PATTERN_11_PRBS7	    (3 << 2)
# define DP_LINK_QUAL_PATTERN_11_MASK	    (3 << 2)

# define DP_RECOVERED_CLOCK_OUT_EN	    (1 << 4)
# define DP_LINK_SCRAMBLING_DISABLE	    (1 << 5)

# define DP_SYMBOL_ERROR_COUNT_BOTH	    (0 << 6)
# define DP_SYMBOL_ERROR_COUNT_DISPARITY    (1 << 6)
# define DP_SYMBOL_ERROR_COUNT_SYMBOL	    (2 << 6)
# define DP_SYMBOL_ERROR_COUNT_MASK	    (3 << 6)

#define DP_TRAINING_LANE0_SET		    0x103
#define DP_TRAINING_LANE1_SET		    0x104
#define DP_TRAINING_LANE2_SET		    0x105
#define DP_TRAINING_LANE3_SET		    0x106

# define DP_TRAIN_VOLTAGE_SWING_MASK	    0x3
# define DP_TRAIN_VOLTAGE_SWING_SHIFT	    0
# define DP_TRAIN_MAX_SWING_REACHED	    (1 << 2)
# define DP_TRAIN_VOLTAGE_SWING_LEVEL_0 (0 << 0)
# define DP_TRAIN_VOLTAGE_SWING_LEVEL_1 (1 << 0)
# define DP_TRAIN_VOLTAGE_SWING_LEVEL_2 (2 << 0)
# define DP_TRAIN_VOLTAGE_SWING_LEVEL_3 (3 << 0)

# define DP_TRAIN_PRE_EMPHASIS_MASK	    (3 << 3)
# define DP_TRAIN_PRE_EMPH_LEVEL_0		(0 << 3)
# define DP_TRAIN_PRE_EMPH_LEVEL_1		(1 << 3)
# define DP_TRAIN_PRE_EMPH_LEVEL_2		(2 << 3)
# define DP_TRAIN_PRE_EMPH_LEVEL_3		(3 << 3)

# define DP_TRAIN_PRE_EMPHASIS_SHIFT	    3
# define DP_TRAIN_MAX_PRE_EMPHASIS_REACHED  (1 << 5)

#define DP_DOWNSPREAD_CTRL		    0x107
# define DP_SPREAD_AMP_0_5		    (1 << 4)
# define DP_MSA_TIMING_PAR_IGNORE_EN	    (1 << 7) /* eDP */

#define DP_MAIN_LINK_CHANNEL_CODING_SET	    0x108
# define DP_SET_ANSI_8B10B		    (1 << 0)

#define DP_I2C_SPEED_CONTROL_STATUS	    0x109   /* DPI */
/* bitmask as for DP_I2C_SPEED_CAP */

#define DP_EDP_CONFIGURATION_SET            0x10a   /* XXX 1.2? */
# define DP_ALTERNATE_SCRAMBLER_RESET_ENABLE (1 << 0)
# define DP_FRAMING_CHANGE_ENABLE	    (1 << 1)
# define DP_PANEL_SELF_TEST_ENABLE	    (1 << 7)

#define DP_LINK_QUAL_LANE0_SET		    0x10b   /* DPCD >= 1.2 */
#define DP_LINK_QUAL_LANE1_SET		    0x10c
#define DP_LINK_QUAL_LANE2_SET		    0x10d
#define DP_LINK_QUAL_LANE3_SET		    0x10e
# define DP_LINK_QUAL_PATTERN_DISABLE	    0
# define DP_LINK_QUAL_PATTERN_D10_2	    1
# define DP_LINK_QUAL_PATTERN_ERROR_RATE    2
# define DP_LINK_QUAL_PATTERN_PRBS7	    3
# define DP_LINK_QUAL_PATTERN_80BIT_CUSTOM  4
# define DP_LINK_QUAL_PATTERN_HBR2_EYE      5
# define DP_LINK_QUAL_PATTERN_MASK	    7

#define DP_TRAINING_LANE0_1_SET2	    0x10f
#define DP_TRAINING_LANE2_3_SET2	    0x110
# define DP_LANE02_POST_CURSOR2_SET_MASK    (3 << 0)
# define DP_LANE02_MAX_POST_CURSOR2_REACHED (1 << 2)
# define DP_LANE13_POST_CURSOR2_SET_MASK    (3 << 4)
# define DP_LANE13_MAX_POST_CURSOR2_REACHED (1 << 6)

#define DP_MSTM_CTRL			    0x111   /* 1.2 */
# define DP_MST_EN			    (1 << 0)
# define DP_UP_REQ_EN			    (1 << 1)
# define DP_UPSTREAM_IS_SRC		    (1 << 2)

#define DP_AUDIO_DELAY0			    0x112   /* 1.2 */
#define DP_AUDIO_DELAY1			    0x113
#define DP_AUDIO_DELAY2			    0x114

#define DP_LINK_RATE_SET		    0x115   /* eDP 1.4 */
# define DP_LINK_RATE_SET_SHIFT		    0
# define DP_LINK_RATE_SET_MASK		    (7 << 0)

#define DP_RECEIVER_ALPM_CONFIG		    0x116   /* eDP 1.4 */
# define DP_ALPM_ENABLE			    (1 << 0)
# define DP_ALPM_LOCK_ERROR_IRQ_HPD_ENABLE  (1 << 1)

#define DP_SINK_DEVICE_AUX_FRAME_SYNC_CONF  0x117   /* eDP 1.4 */
# define DP_AUX_FRAME_SYNC_ENABLE	    (1 << 0)
# define DP_IRQ_HPD_ENABLE		    (1 << 1)

#define DP_UPSTREAM_DEVICE_DP_PWR_NEED	    0x118   /* 1.2 */
# define DP_PWR_NOT_NEEDED		    (1 << 0)

#define DP_FEC_CONFIGURATION		    0x120    /* 1.4 */
# define DP_FEC_READY			    (1 << 0)
# define DP_FEC_ERR_COUNT_SEL_MASK	    (7 << 1)
# define DP_FEC_ERR_COUNT_DIS		    (0 << 1)
# define DP_FEC_UNCORR_BLK_ERROR_COUNT	    (1 << 1)
# define DP_FEC_CORR_BLK_ERROR_COUNT	    (2 << 1)
# define DP_FEC_BIT_ERROR_COUNT		    (3 << 1)
# define DP_FEC_LANE_SELECT_MASK	    (3 << 4)
# define DP_FEC_LANE_0_SELECT		    (0 << 4)
# define DP_FEC_LANE_1_SELECT		    (1 << 4)
# define DP_FEC_LANE_2_SELECT		    (2 << 4)
# define DP_FEC_LANE_3_SELECT		    (3 << 4)

#define DP_AUX_FRAME_SYNC_VALUE		    0x15c   /* eDP 1.4 */
# define DP_AUX_FRAME_SYNC_VALID	    (1 << 0)

#define DP_DSC_ENABLE                       0x160   /* DP 1.4 */
# define DP_DECOMPRESSION_EN                (1 << 0)

#define DP_PSR_EN_CFG			    0x170   /* XXX 1.2? */
# define DP_PSR_ENABLE			    (1 << 0)
# define DP_PSR_MAIN_LINK_ACTIVE	    (1 << 1)
# define DP_PSR_CRC_VERIFICATION	    (1 << 2)
# define DP_PSR_FRAME_CAPTURE		    (1 << 3)
# define DP_PSR_SELECTIVE_UPDATE	    (1 << 4)
# define DP_PSR_IRQ_HPD_WITH_CRC_ERRORS     (1 << 5)
# define DP_PSR_ENABLE_PSR2		    (1 << 6) /* eDP 1.4a */

#define DP_ADAPTER_CTRL			    0x1a0
# define DP_ADAPTER_CTRL_FORCE_LOAD_SENSE   (1 << 0)

#define DP_BRANCH_DEVICE_CTRL		    0x1a1
# define DP_BRANCH_DEVICE_IRQ_HPD	    (1 << 0)

#define DP_PAYLOAD_ALLOCATE_SET		    0x1c0
#define DP_PAYLOAD_ALLOCATE_START_TIME_SLOT 0x1c1
#define DP_PAYLOAD_ALLOCATE_TIME_SLOT_COUNT 0x1c2

#define DP_SINK_COUNT			    0x200
/* prior to 1.2 bit 7 was reserved mbz */
# define DP_GET_SINK_COUNT(x)		    ((((x) & 0x80) >> 1) | ((x) & 0x3f))
# define DP_SINK_CP_READY		    (1 << 6)

#define DP_DEVICE_SERVICE_IRQ_VECTOR	    0x201
# define DP_REMOTE_CONTROL_COMMAND_PENDING  (1 << 0)
# define DP_AUTOMATED_TEST_REQUEST	    (1 << 1)
# define DP_CP_IRQ			    (1 << 2)
# define DP_MCCS_IRQ			    (1 << 3)
# define DP_DOWN_REP_MSG_RDY		    (1 << 4) /* 1.2 MST */
# define DP_UP_REQ_MSG_RDY		    (1 << 5) /* 1.2 MST */
# define DP_SINK_SPECIFIC_IRQ		    (1 << 6)

#define DP_LANE0_1_STATUS		    0x202
#define DP_LANE2_3_STATUS		    0x203
# define DP_LANE_CR_DONE		    (1 << 0)
# define DP_LANE_CHANNEL_EQ_DONE	    (1 << 1)
# define DP_LANE_SYMBOL_LOCKED		    (1 << 2)

#define DP_CHANNEL_EQ_BITS (DP_LANE_CR_DONE |		\
			    DP_LANE_CHANNEL_EQ_DONE |	\
			    DP_LANE_SYMBOL_LOCKED)

#define DP_LANE_ALIGN_STATUS_UPDATED	    0x204

#define DP_INTERLANE_ALIGN_DONE		    (1 << 0)
#define DP_DOWNSTREAM_PORT_STATUS_CHANGED   (1 << 6)
#define DP_LINK_STATUS_UPDATED		    (1 << 7)

#define DP_SINK_STATUS			    0x205

#define DP_RECEIVE_PORT_0_STATUS	    (1 << 0)
#define DP_RECEIVE_PORT_1_STATUS	    (1 << 1)

#define DP_ADJUST_REQUEST_LANE0_1	    0x206
#define DP_ADJUST_REQUEST_LANE2_3	    0x207
# define DP_ADJUST_VOLTAGE_SWING_LANE0_MASK  0x03
# define DP_ADJUST_VOLTAGE_SWING_LANE0_SHIFT 0
# define DP_ADJUST_PRE_EMPHASIS_LANE0_MASK   0x0c
# define DP_ADJUST_PRE_EMPHASIS_LANE0_SHIFT  2
# define DP_ADJUST_VOLTAGE_SWING_LANE1_MASK  0x30
# define DP_ADJUST_VOLTAGE_SWING_LANE1_SHIFT 4
# define DP_ADJUST_PRE_EMPHASIS_LANE1_MASK   0xc0
# define DP_ADJUST_PRE_EMPHASIS_LANE1_SHIFT  6

#define DP_ADJUST_REQUEST_POST_CURSOR2      0x20c
# define DP_ADJUST_POST_CURSOR2_LANE0_MASK  0x03
# define DP_ADJUST_POST_CURSOR2_LANE0_SHIFT 0
# define DP_ADJUST_POST_CURSOR2_LANE1_MASK  0x0c
# define DP_ADJUST_POST_CURSOR2_LANE1_SHIFT 2
# define DP_ADJUST_POST_CURSOR2_LANE2_MASK  0x30
# define DP_ADJUST_POST_CURSOR2_LANE2_SHIFT 4
# define DP_ADJUST_POST_CURSOR2_LANE3_MASK  0xc0
# define DP_ADJUST_POST_CURSOR2_LANE3_SHIFT 6

#define DP_TEST_REQUEST			    0x218
# define DP_TEST_LINK_TRAINING		    (1 << 0)
# define DP_TEST_LINK_VIDEO_PATTERN	    (1 << 1)
# define DP_TEST_LINK_EDID_READ		    (1 << 2)
# define DP_TEST_LINK_PHY_TEST_PATTERN	    (1 << 3) /* DPCD >= 1.1 */
# define DP_TEST_LINK_FAUX_PATTERN	    (1 << 4) /* DPCD >= 1.2 */
# define DP_TEST_LINK_AUDIO_PATTERN         (1 << 5) /* DPCD >= 1.2 */
# define DP_TEST_LINK_AUDIO_DISABLED_VIDEO  (1 << 6) /* DPCD >= 1.2 */

#define DP_TEST_LINK_RATE		    0x219
# define DP_LINK_RATE_162		    (0x6)
# define DP_LINK_RATE_27		    (0xa)

#define DP_TEST_LANE_COUNT		    0x220

#define DP_TEST_PATTERN			    0x221
# define DP_NO_TEST_PATTERN                 0x0
# define DP_COLOR_RAMP                      0x1
# define DP_BLACK_AND_WHITE_VERTICAL_LINES  0x2
# define DP_COLOR_SQUARE                    0x3

#define DP_TEST_H_TOTAL_HI                  0x222
#define DP_TEST_H_TOTAL_LO                  0x223

#define DP_TEST_V_TOTAL_HI                  0x224
#define DP_TEST_V_TOTAL_LO                  0x225

#define DP_TEST_H_START_HI                  0x226
#define DP_TEST_H_START_LO                  0x227

#define DP_TEST_V_START_HI                  0x228
#define DP_TEST_V_START_LO                  0x229

#define DP_TEST_HSYNC_HI                    0x22A
# define DP_TEST_HSYNC_POLARITY             (1 << 7)
# define DP_TEST_HSYNC_WIDTH_HI_MASK        (127 << 0)
#define DP_TEST_HSYNC_WIDTH_LO              0x22B

#define DP_TEST_VSYNC_HI                    0x22C
# define DP_TEST_VSYNC_POLARITY             (1 << 7)
# define DP_TEST_VSYNC_WIDTH_HI_MASK        (127 << 0)
#define DP_TEST_VSYNC_WIDTH_LO              0x22D

#define DP_TEST_H_WIDTH_HI                  0x22E
#define DP_TEST_H_WIDTH_LO                  0x22F

#define DP_TEST_V_HEIGHT_HI                 0x230
#define DP_TEST_V_HEIGHT_LO                 0x231

#define DP_TEST_MISC0                       0x232
# define DP_TEST_SYNC_CLOCK                 (1 << 0)
# define DP_TEST_COLOR_FORMAT_MASK          (3 << 1)
# define DP_TEST_COLOR_FORMAT_SHIFT         1
# define DP_COLOR_FORMAT_RGB                (0 << 1)
# define DP_COLOR_FORMAT_YCbCr422           (1 << 1)
# define DP_COLOR_FORMAT_YCbCr444           (2 << 1)
# define DP_TEST_DYNAMIC_RANGE_VESA         (0 << 3)
# define DP_TEST_DYNAMIC_RANGE_CEA          (1 << 3)
# define DP_TEST_YCBCR_COEFFICIENTS         (1 << 4)
# define DP_YCBCR_COEFFICIENTS_ITU601       (0 << 4)
# define DP_YCBCR_COEFFICIENTS_ITU709       (1 << 4)
# define DP_TEST_BIT_DEPTH_MASK             (7 << 5)
# define DP_TEST_BIT_DEPTH_SHIFT            5
# define DP_TEST_BIT_DEPTH_6                (0 << 5)
# define DP_TEST_BIT_DEPTH_8                (1 << 5)
# define DP_TEST_BIT_DEPTH_10               (2 << 5)
# define DP_TEST_BIT_DEPTH_12               (3 << 5)
# define DP_TEST_BIT_DEPTH_16               (4 << 5)

#define DP_TEST_MISC1                       0x233
# define DP_TEST_REFRESH_DENOMINATOR        (1 << 0)
# define DP_TEST_INTERLACED                 (1 << 1)

#define DP_TEST_REFRESH_RATE_NUMERATOR      0x234

#define DP_TEST_MISC0                       0x232

#define DP_TEST_CRC_R_CR		    0x240
#define DP_TEST_CRC_G_Y			    0x242
#define DP_TEST_CRC_B_CB		    0x244

#define DP_TEST_SINK_MISC		    0x246
# define DP_TEST_CRC_SUPPORTED		    (1 << 5)
# define DP_TEST_COUNT_MASK		    0xf

#define DP_PHY_TEST_PATTERN                 0x248
# define DP_PHY_TEST_PATTERN_SEL_MASK       0x7
# define DP_PHY_TEST_PATTERN_NONE           0x0
# define DP_PHY_TEST_PATTERN_D10_2          0x1
# define DP_PHY_TEST_PATTERN_ERROR_COUNT    0x2
# define DP_PHY_TEST_PATTERN_PRBS7          0x3
# define DP_PHY_TEST_PATTERN_80BIT_CUSTOM   0x4
# define DP_PHY_TEST_PATTERN_CP2520         0x5

#define DP_TEST_HBR2_SCRAMBLER_RESET        0x24A
#define DP_TEST_80BIT_CUSTOM_PATTERN_7_0    0x250
#define	DP_TEST_80BIT_CUSTOM_PATTERN_15_8   0x251
#define	DP_TEST_80BIT_CUSTOM_PATTERN_23_16  0x252
#define	DP_TEST_80BIT_CUSTOM_PATTERN_31_24  0x253
#define	DP_TEST_80BIT_CUSTOM_PATTERN_39_32  0x254
#define	DP_TEST_80BIT_CUSTOM_PATTERN_47_40  0x255
#define	DP_TEST_80BIT_CUSTOM_PATTERN_55_48  0x256
#define	DP_TEST_80BIT_CUSTOM_PATTERN_63_56  0x257
#define	DP_TEST_80BIT_CUSTOM_PATTERN_71_64  0x258
#define	DP_TEST_80BIT_CUSTOM_PATTERN_79_72  0x259

#define DP_TEST_RESPONSE		    0x260
# define DP_TEST_ACK			    (1 << 0)
# define DP_TEST_NAK			    (1 << 1)
# define DP_TEST_EDID_CHECKSUM_WRITE	    (1 << 2)

#define DP_TEST_EDID_CHECKSUM		    0x261

#define DP_TEST_SINK			    0x270
# define DP_TEST_SINK_START		    (1 << 0)
#define DP_TEST_AUDIO_MODE		    0x271
#define DP_TEST_AUDIO_PATTERN_TYPE	    0x272
#define DP_TEST_AUDIO_PERIOD_CH1	    0x273
#define DP_TEST_AUDIO_PERIOD_CH2	    0x274
#define DP_TEST_AUDIO_PERIOD_CH3	    0x275
#define DP_TEST_AUDIO_PERIOD_CH4	    0x276
#define DP_TEST_AUDIO_PERIOD_CH5	    0x277
#define DP_TEST_AUDIO_PERIOD_CH6	    0x278
#define DP_TEST_AUDIO_PERIOD_CH7	    0x279
#define DP_TEST_AUDIO_PERIOD_CH8	    0x27A

#define DP_FEC_STATUS			    0x280    /* 1.4 */
# define DP_FEC_DECODE_EN_DETECTED	    (1 << 0)
# define DP_FEC_DECODE_DIS_DETECTED	    (1 << 1)

#define DP_FEC_ERROR_COUNT_LSB		    0x0281    /* 1.4 */

#define DP_FEC_ERROR_COUNT_MSB		    0x0282    /* 1.4 */
# define DP_FEC_ERROR_COUNT_MASK	    0x7F
# define DP_FEC_ERR_COUNT_VALID		    (1 << 7)

#define DP_PAYLOAD_TABLE_UPDATE_STATUS      0x2c0   /* 1.2 MST */
# define DP_PAYLOAD_TABLE_UPDATED           (1 << 0)
# define DP_PAYLOAD_ACT_HANDLED             (1 << 1)

#define DP_VC_PAYLOAD_ID_SLOT_1             0x2c1   /* 1.2 MST */
/* up to ID_SLOT_63 at 0x2ff */

#define DP_SOURCE_OUI			    0x300
#define DP_SINK_OUI			    0x400
#define DP_BRANCH_OUI			    0x500
#define DP_BRANCH_ID                        0x503
#define DP_BRANCH_REVISION_START            0x509
#define DP_BRANCH_HW_REV                    0x509
#define DP_BRANCH_SW_REV                    0x50A

#define DP_SET_POWER                        0x600
# define DP_SET_POWER_D0                    0x1
# define DP_SET_POWER_D3                    0x2
# define DP_SET_POWER_MASK                  0x3
# define DP_SET_POWER_D3_AUX_ON             0x5

#define DP_EDP_DPCD_REV			    0x700    /* eDP 1.2 */
# define DP_EDP_11			    0x00
# define DP_EDP_12			    0x01
# define DP_EDP_13			    0x02
# define DP_EDP_14			    0x03
# define DP_EDP_14a                         0x04    /* eDP 1.4a */
# define DP_EDP_14b                         0x05    /* eDP 1.4b */

#define DP_EDP_GENERAL_CAP_1		    0x701
# define DP_EDP_TCON_BACKLIGHT_ADJUSTMENT_CAP		(1 << 0)
# define DP_EDP_BACKLIGHT_PIN_ENABLE_CAP		(1 << 1)
# define DP_EDP_BACKLIGHT_AUX_ENABLE_CAP		(1 << 2)
# define DP_EDP_PANEL_SELF_TEST_PIN_ENABLE_CAP		(1 << 3)
# define DP_EDP_PANEL_SELF_TEST_AUX_ENABLE_CAP		(1 << 4)
# define DP_EDP_FRC_ENABLE_CAP				(1 << 5)
# define DP_EDP_COLOR_ENGINE_CAP			(1 << 6)
# define DP_EDP_SET_POWER_CAP				(1 << 7)

#define DP_EDP_BACKLIGHT_ADJUSTMENT_CAP     0x702
# define DP_EDP_BACKLIGHT_BRIGHTNESS_PWM_PIN_CAP	(1 << 0)
# define DP_EDP_BACKLIGHT_BRIGHTNESS_AUX_SET_CAP	(1 << 1)
# define DP_EDP_BACKLIGHT_BRIGHTNESS_BYTE_COUNT		(1 << 2)
# define DP_EDP_BACKLIGHT_AUX_PWM_PRODUCT_CAP		(1 << 3)
# define DP_EDP_BACKLIGHT_FREQ_PWM_PIN_PASSTHRU_CAP	(1 << 4)
# define DP_EDP_BACKLIGHT_FREQ_AUX_SET_CAP		(1 << 5)
# define DP_EDP_DYNAMIC_BACKLIGHT_CAP			(1 << 6)
# define DP_EDP_VBLANK_BACKLIGHT_UPDATE_CAP		(1 << 7)

#define DP_EDP_GENERAL_CAP_2		    0x703
# define DP_EDP_OVERDRIVE_ENGINE_ENABLED		(1 << 0)

#define DP_EDP_GENERAL_CAP_3		    0x704    /* eDP 1.4 */
# define DP_EDP_X_REGION_CAP_MASK			(0xf << 0)
# define DP_EDP_X_REGION_CAP_SHIFT			0
# define DP_EDP_Y_REGION_CAP_MASK			(0xf << 4)
# define DP_EDP_Y_REGION_CAP_SHIFT			4

#define DP_EDP_DISPLAY_CONTROL_REGISTER     0x720
# define DP_EDP_BACKLIGHT_ENABLE			(1 << 0)
# define DP_EDP_BLACK_VIDEO_ENABLE			(1 << 1)
# define DP_EDP_FRC_ENABLE				(1 << 2)
# define DP_EDP_COLOR_ENGINE_ENABLE			(1 << 3)
# define DP_EDP_VBLANK_BACKLIGHT_UPDATE_ENABLE		(1 << 7)

#define DP_EDP_BACKLIGHT_MODE_SET_REGISTER  0x721
# define DP_EDP_BACKLIGHT_CONTROL_MODE_MASK		(3 << 0)
# define DP_EDP_BACKLIGHT_CONTROL_MODE_PWM		(0 << 0)
# define DP_EDP_BACKLIGHT_CONTROL_MODE_PRESET		(1 << 0)
# define DP_EDP_BACKLIGHT_CONTROL_MODE_DPCD		(2 << 0)
# define DP_EDP_BACKLIGHT_CONTROL_MODE_PRODUCT		(3 << 0)
# define DP_EDP_BACKLIGHT_FREQ_PWM_PIN_PASSTHRU_ENABLE	(1 << 2)
# define DP_EDP_BACKLIGHT_FREQ_AUX_SET_ENABLE		(1 << 3)
# define DP_EDP_DYNAMIC_BACKLIGHT_ENABLE		(1 << 4)
# define DP_EDP_REGIONAL_BACKLIGHT_ENABLE		(1 << 5)
# define DP_EDP_UPDATE_REGION_BRIGHTNESS		(1 << 6) /* eDP 1.4 */

#define DP_EDP_BACKLIGHT_BRIGHTNESS_MSB     0x722
#define DP_EDP_BACKLIGHT_BRIGHTNESS_LSB     0x723

#define DP_EDP_PWMGEN_BIT_COUNT             0x724
#define DP_EDP_PWMGEN_BIT_COUNT_CAP_MIN     0x725
#define DP_EDP_PWMGEN_BIT_COUNT_CAP_MAX     0x726
# define DP_EDP_PWMGEN_BIT_COUNT_MASK       (0x1f << 0)

#define DP_EDP_BACKLIGHT_CONTROL_STATUS     0x727

#define DP_EDP_BACKLIGHT_FREQ_SET           0x728
# define DP_EDP_BACKLIGHT_FREQ_BASE_KHZ     27000

#define DP_EDP_BACKLIGHT_FREQ_CAP_MIN_MSB   0x72a
#define DP_EDP_BACKLIGHT_FREQ_CAP_MIN_MID   0x72b
#define DP_EDP_BACKLIGHT_FREQ_CAP_MIN_LSB   0x72c

#define DP_EDP_BACKLIGHT_FREQ_CAP_MAX_MSB   0x72d
#define DP_EDP_BACKLIGHT_FREQ_CAP_MAX_MID   0x72e
#define DP_EDP_BACKLIGHT_FREQ_CAP_MAX_LSB   0x72f

#define DP_EDP_DBC_MINIMUM_BRIGHTNESS_SET   0x732
#define DP_EDP_DBC_MAXIMUM_BRIGHTNESS_SET   0x733

#define DP_EDP_REGIONAL_BACKLIGHT_BASE      0x740    /* eDP 1.4 */
#define DP_EDP_REGIONAL_BACKLIGHT_0	    0x741    /* eDP 1.4 */

#define DP_SIDEBAND_MSG_DOWN_REQ_BASE	    0x1000   /* 1.2 MST */
#define DP_SIDEBAND_MSG_UP_REP_BASE	    0x1200   /* 1.2 MST */
#define DP_SIDEBAND_MSG_DOWN_REP_BASE	    0x1400   /* 1.2 MST */
#define DP_SIDEBAND_MSG_UP_REQ_BASE	    0x1600   /* 1.2 MST */

#define DP_SINK_COUNT_ESI		    0x2enum port /* 0-5 sink count */
# define DP_SINK_COUNT_CP_READY             (1 << 6)

#define DP_DEVICE_SERVICE_IRQ_VECTOR_ESI0   0x2003   /* 1.2 */

#define DP_DEVICE_SERVICE_IRQ_VECTOR_ESI1   0x2004   /* 1.2 */
# define DP_RX_GTC_MSTR_REQ_STATUS_CHANGE    (1 << 0)
# define DP_LOCK_ACQUISITION_REQUEST         (1 << 1)
# define DP_CEC_IRQ                          (1 << 2)

#define DP_LINK_SERVICE_IRQ_VECTOR_ESI0     0x2005   /* 1.2 */

#define DP_PSR_ERROR_STATUS                 0x2006  /* XXX 1.2? */
# define DP_PSR_LINK_CRC_ERROR              (1 << 0)
# define DP_PSR_RFB_STORAGE_ERROR           (1 << 1)
# define DP_PSR_VSC_SDP_UNCORRECTABLE_ERROR (1 << 2) /* eDP 1.4 */

#define DP_PSR_ESI                          0x2007  /* XXX 1.2? */
# define DP_PSR_CAPS_CHANGE                 (1 << 0)

#define DP_PSR_STATUS                       0x2008  /* XXX 1.2? */
# define DP_PSR_SINK_INACTIVE               0
# define DP_PSR_SINK_ACTIVE_SRC_SYNCED      1
# define DP_PSR_SINK_ACTIVE_RFB             2
# define DP_PSR_SINK_ACTIVE_SINK_SYNCED     3
# define DP_PSR_SINK_ACTIVE_RESYNC          4
# define DP_PSR_SINK_INTERNAL_ERROR         7
# define DP_PSR_SINK_STATE_MASK             0x07

#define DP_SYNCHRONIZATION_LATENCY_IN_SINK		0x2009 /* edp 1.4 */
# define DP_MAX_RESYNC_FRAME_COUNT_MASK			(0xf << 0)
# define DP_MAX_RESYNC_FRAME_COUNT_SHIFT		0
# define DP_LAST_ACTUAL_SYNCHRONIZATION_LATENCY_MASK	(0xf << 4)
# define DP_LAST_ACTUAL_SYNCHRONIZATION_LATENCY_SHIFT	4

#define DP_LAST_RECEIVED_PSR_SDP	    0x200a /* eDP 1.2 */
# define DP_PSR_STATE_BIT		    (1 << 0) /* eDP 1.2 */
# define DP_UPDATE_RFB_BIT		    (1 << 1) /* eDP 1.2 */
# define DP_CRC_VALID_BIT		    (1 << 2) /* eDP 1.2 */
# define DP_SU_VALID			    (1 << 3) /* eDP 1.4 */
# define DP_FIRST_SCAN_LINE_SU_REGION	    (1 << 4) /* eDP 1.4 */
# define DP_LAST_SCAN_LINE_SU_REGION	    (1 << 5) /* eDP 1.4 */
# define DP_Y_COORDINATE_VALID		    (1 << 6) /* eDP 1.4a */

#define DP_RECEIVER_ALPM_STATUS		    0x200b  /* eDP 1.4 */
# define DP_ALPM_LOCK_TIMEOUT_ERROR	    (1 << 0)

#define DP_LANE0_1_STATUS_ESI                  0x200c /* status same as 0x202 */
#define DP_LANE2_3_STATUS_ESI                  0x200d /* status same as 0x203 */
#define DP_LANE_ALIGN_STATUS_UPDATED_ESI       0x200e /* status same as 0x204 */
#define DP_SINK_STATUS_ESI                     0x200f /* status same as 0x205 */

#define DP_DP13_DPCD_REV                    0x2200
#define DP_DP13_MAX_LINK_RATE               0x2201

#define DP_DPRX_FEATURE_ENUMERATION_LIST    0x2210  /* DP 1.3 */
# define DP_GTC_CAP					(1 << 0)  /* DP 1.3 */
# define DP_SST_SPLIT_SDP_CAP				(1 << 1)  /* DP 1.4 */
# define DP_AV_SYNC_CAP					(1 << 2)  /* DP 1.3 */
# define DP_VSC_SDP_EXT_FOR_COLORIMETRY_SUPPORTED	(1 << 3)  /* DP 1.3 */
# define DP_VSC_EXT_VESA_SDP_SUPPORTED			(1 << 4)  /* DP 1.4 */
# define DP_VSC_EXT_VESA_SDP_CHAINING_SUPPORTED		(1 << 5)  /* DP 1.4 */
# define DP_VSC_EXT_CEA_SDP_SUPPORTED			(1 << 6)  /* DP 1.4 */
# define DP_VSC_EXT_CEA_SDP_CHAINING_SUPPORTED		(1 << 7)  /* DP 1.4 */

/* HDMI CEC tunneling over AUX DP 1.3 section 5.3.3.3.1 DPCD 1.4+ */
#define DP_CEC_TUNNELING_CAPABILITY            0x3000
# define DP_CEC_TUNNELING_CAPABLE               (1 << 0)
# define DP_CEC_SNOOPING_CAPABLE                (1 << 1)
# define DP_CEC_MULTIPLE_LA_CAPABLE             (1 << 2)

#define DP_CEC_TUNNELING_CONTROL               0x3001
# define DP_CEC_TUNNELING_ENABLE                (1 << 0)
# define DP_CEC_SNOOPING_ENABLE                 (1 << 1)

#define DP_CEC_RX_MESSAGE_INFO                 0x3002
# define DP_CEC_RX_MESSAGE_LEN_MASK             (0xf << 0)
# define DP_CEC_RX_MESSAGE_LEN_SHIFT            0
# define DP_CEC_RX_MESSAGE_HPD_STATE            (1 << 4)
# define DP_CEC_RX_MESSAGE_HPD_LOST             (1 << 5)
# define DP_CEC_RX_MESSAGE_ACKED                (1 << 6)
# define DP_CEC_RX_MESSAGE_ENDED                (1 << 7)

#define DP_CEC_TX_MESSAGE_INFO                 0x3003
# define DP_CEC_TX_MESSAGE_LEN_MASK             (0xf << 0)
# define DP_CEC_TX_MESSAGE_LEN_SHIFT            0
# define DP_CEC_TX_RETRY_COUNT_MASK             (0x7 << 4)
# define DP_CEC_TX_RETRY_COUNT_SHIFT            4
# define DP_CEC_TX_MESSAGE_SEND                 (1 << 7)

#define DP_CEC_TUNNELING_IRQ_FLAGS             0x3004
# define DP_CEC_RX_MESSAGE_INFO_VALID           (1 << 0)
# define DP_CEC_RX_MESSAGE_OVERFLOW             (1 << 1)
# define DP_CEC_TX_MESSAGE_SENT                 (1 << 4)
# define DP_CEC_TX_LINE_ERROR                   (1 << 5)
# define DP_CEC_TX_ADDRESS_NACK_ERROR           (1 << 6)
# define DP_CEC_TX_DATA_NACK_ERROR              (1 << 7)

#define DP_CEC_LOGICAL_ADDRESS_MASK            0x300E /* 0x300F word */
# define DP_CEC_LOGICAL_ADDRESS_0               (1 << 0)
# define DP_CEC_LOGICAL_ADDRESS_1               (1 << 1)
# define DP_CEC_LOGICAL_ADDRESS_2               (1 << 2)
# define DP_CEC_LOGICAL_ADDRESS_3               (1 << 3)
# define DP_CEC_LOGICAL_ADDRESS_4               (1 << 4)
# define DP_CEC_LOGICAL_ADDRESS_5               (1 << 5)
# define DP_CEC_LOGICAL_ADDRESS_6               (1 << 6)
# define DP_CEC_LOGICAL_ADDRESS_7               (1 << 7)
#define DP_CEC_LOGICAL_ADDRESS_MASK_2          0x300F /* 0x300E word */
# define DP_CEC_LOGICAL_ADDRESS_8               (1 << 0)
# define DP_CEC_LOGICAL_ADDRESS_9               (1 << 1)
# define DP_CEC_LOGICAL_ADDRESS_10              (1 << 2)
# define DP_CEC_LOGICAL_ADDRESS_11              (1 << 3)
# define DP_CEC_LOGICAL_ADDRESS_12              (1 << 4)
# define DP_CEC_LOGICAL_ADDRESS_13              (1 << 5)
# define DP_CEC_LOGICAL_ADDRESS_14              (1 << 6)
# define DP_CEC_LOGICAL_ADDRESS_15              (1 << 7)

#define DP_CEC_RX_MESSAGE_BUFFER               0x3010
#define DP_CEC_TX_MESSAGE_BUFFER               0x3020
#define DP_CEC_MESSAGE_BUFFER_LENGTH             0x10

#define DP_AUX_HDCP_BKSV		0x68000
#define DP_AUX_HDCP_RI_PRIME		0x68005
#define DP_AUX_HDCP_AKSV		0x68007
#define DP_AUX_HDCP_AN			0x6800C
#define DP_AUX_HDCP_V_PRIME(h)		(0x68014 + h * 4)
#define DP_AUX_HDCP_BCAPS		0x68028
# define DP_BCAPS_REPEATER_PRESENT	BIT(1)
# define DP_BCAPS_HDCP_CAPABLE		BIT(0)
#define DP_AUX_HDCP_BSTATUS		0x68029
# define DP_BSTATUS_REAUTH_REQ		BIT(3)
# define DP_BSTATUS_LINK_FAILURE	BIT(2)
# define DP_BSTATUS_R0_PRIME_READY	BIT(1)
# define DP_BSTATUS_READY		BIT(0)
#define DP_AUX_HDCP_BINFO		0x6802A
#define DP_AUX_HDCP_KSV_FIFO		0x6802C
#define DP_AUX_HDCP_AINFO		0x6803B

/* DP HDCP2.2 parameter offsets in DPCD address space */
#define DP_HDCP_2_2_REG_RTX_OFFSET		0x69000
#define DP_HDCP_2_2_REG_TXCAPS_OFFSET		0x69008
#define DP_HDCP_2_2_REG_CERT_RX_OFFSET		0x6900B
#define DP_HDCP_2_2_REG_RRX_OFFSET		0x69215
#define DP_HDCP_2_2_REG_RX_CAPS_OFFSET		0x6921D
#define DP_HDCP_2_2_REG_EKPUB_KM_OFFSET		0x69220
#define DP_HDCP_2_2_REG_EKH_KM_WR_OFFSET	0x692A0
#define DP_HDCP_2_2_REG_M_OFFSET		0x692B0
#define DP_HDCP_2_2_REG_HPRIME_OFFSET		0x692C0
#define DP_HDCP_2_2_REG_EKH_KM_RD_OFFSET	0x692E0
#define DP_HDCP_2_2_REG_RN_OFFSET		0x692F0
#define DP_HDCP_2_2_REG_LPRIME_OFFSET		0x692F8
#define DP_HDCP_2_2_REG_EDKEY_KS_OFFSET		0x69318
#define	DP_HDCP_2_2_REG_RIV_OFFSET		0x69328
#define DP_HDCP_2_2_REG_RXINFO_OFFSET		0x69330
#define DP_HDCP_2_2_REG_SEQ_NUM_V_OFFSET	0x69332
#define DP_HDCP_2_2_REG_VPRIME_OFFSET		0x69335
#define DP_HDCP_2_2_REG_RECV_ID_LIST_OFFSET	0x69345
#define DP_HDCP_2_2_REG_V_OFFSET		0x693E0
#define DP_HDCP_2_2_REG_SEQ_NUM_M_OFFSET	0x693F0
#define DP_HDCP_2_2_REG_K_OFFSET		0x693F3
#define DP_HDCP_2_2_REG_STREAM_ID_TYPE_OFFSET	0x693F5
#define DP_HDCP_2_2_REG_MPRIME_OFFSET		0x69473
#define DP_HDCP_2_2_REG_RXSTATUS_OFFSET		0x69493
#define DP_HDCP_2_2_REG_STREAM_TYPE_OFFSET	0x69494
#define DP_HDCP_2_2_REG_DBG_OFFSET		0x69518

/* Link Training (LT)-tunable PHY Repeaters */
#define DP_LT_TUNABLE_PHY_REPEATER_FIELD_DATA_STRUCTURE_REV 0xf0000 /* 1.3 */
#define DP_MAX_LINK_RATE_PHY_REPEATER			    0xf0001 /* 1.4a */
#define DP_PHY_REPEATER_CNT				    0xf0002 /* 1.3 */
#define DP_PHY_REPEATER_MODE				    0xf0003 /* 1.3 */
#define DP_MAX_LANE_COUNT_PHY_REPEATER			    0xf0004 /* 1.4a */
#define DP_Repeater_FEC_CAPABILITY			    0xf0004 /* 1.4 */
#define DP_PHY_REPEATER_EXTENDED_WAIT_TIMEOUT		    0xf0005 /* 1.4a */
#define DP_TRAINING_PATTERN_SET_PHY_REPEATER1		    0xf0010 /* 1.3 */
#define DP_TRAINING_LANE0_SET_PHY_REPEATER1		    0xf0011 /* 1.3 */
#define DP_TRAINING_LANE1_SET_PHY_REPEATER1		    0xf0012 /* 1.3 */
#define DP_TRAINING_LANE2_SET_PHY_REPEATER1		    0xf0013 /* 1.3 */
#define DP_TRAINING_LANE3_SET_PHY_REPEATER1		    0xf0014 /* 1.3 */
#define DP_TRAINING_AUX_RD_INTERVAL_PHY_REPEATER1	    0xf0020 /* 1.4a */
#define DP_TRANSMITTER_CAPABILITY_PHY_REPEATER1		    0xf0021 /* 1.4a */
#define DP_LANE0_1_STATUS_PHY_REPEATER1			    0xf0030 /* 1.3 */
#define DP_LANE2_3_STATUS_PHY_REPEATER1			    0xf0031 /* 1.3 */
#define DP_LANE_ALIGN_STATUS_UPDATED_PHY_REPEATER1	    0xf0032 /* 1.3 */
#define DP_ADJUST_REQUEST_LANE0_1_PHY_REPEATER1		    0xf0033 /* 1.3 */
#define DP_ADJUST_REQUEST_LANE2_3_PHY_REPEATER1		    0xf0034 /* 1.3 */
#define DP_SYMBOL_ERROR_COUNT_LANE0_PHY_REPEATER1	    0xf0035 /* 1.3 */
#define DP_SYMBOL_ERROR_COUNT_LANE1_PHY_REPEATER1	    0xf0037 /* 1.3 */
#define DP_SYMBOL_ERROR_COUNT_LANE2_PHY_REPEATER1	    0xf0039 /* 1.3 */
#define DP_SYMBOL_ERROR_COUNT_LANE3_PHY_REPEATER1	    0xf003b /* 1.3 */
#define DP_FEC_STATUS_PHY_REPEATER1			    0xf0290 /* 1.4 */
#define DP_FEC_ERROR_COUNT_PHY_REPEATER1                    0xf0291 /* 1.4 */
#define DP_FEC_CAPABILITY_PHY_REPEATER1                     0xf0294 /* 1.4a */

/* Repeater modes */
#define DP_PHY_REPEATER_MODE_TRANSPARENT		    0x55    /* 1.3 */
#define DP_PHY_REPEATER_MODE_NON_TRANSPARENT		    0xaa    /* 1.3 */

/* DP HDCP message start offsets in DPCD address space */
#define DP_HDCP_2_2_AKE_INIT_OFFSET		DP_HDCP_2_2_REG_RTX_OFFSET
#define DP_HDCP_2_2_AKE_SEND_CERT_OFFSET	DP_HDCP_2_2_REG_CERT_RX_OFFSET
#define DP_HDCP_2_2_AKE_NO_STORED_KM_OFFSET	DP_HDCP_2_2_REG_EKPUB_KM_OFFSET
#define DP_HDCP_2_2_AKE_STORED_KM_OFFSET	DP_HDCP_2_2_REG_EKH_KM_WR_OFFSET
#define DP_HDCP_2_2_AKE_SEND_HPRIME_OFFSET	DP_HDCP_2_2_REG_HPRIME_OFFSET
#define DP_HDCP_2_2_AKE_SEND_PAIRING_INFO_OFFSET \
						DP_HDCP_2_2_REG_EKH_KM_RD_OFFSET
#define DP_HDCP_2_2_LC_INIT_OFFSET		DP_HDCP_2_2_REG_RN_OFFSET
#define DP_HDCP_2_2_LC_SEND_LPRIME_OFFSET	DP_HDCP_2_2_REG_LPRIME_OFFSET
#define DP_HDCP_2_2_SKE_SEND_EKS_OFFSET		DP_HDCP_2_2_REG_EDKEY_KS_OFFSET
#define DP_HDCP_2_2_REP_SEND_RECVID_LIST_OFFSET	DP_HDCP_2_2_REG_RXINFO_OFFSET
#define DP_HDCP_2_2_REP_SEND_ACK_OFFSET		DP_HDCP_2_2_REG_V_OFFSET
#define DP_HDCP_2_2_REP_STREAM_MANAGE_OFFSET	DP_HDCP_2_2_REG_SEQ_NUM_M_OFFSET
#define DP_HDCP_2_2_REP_STREAM_READY_OFFSET	DP_HDCP_2_2_REG_MPRIME_OFFSET

#define HDCP_2_2_DP_RXSTATUS_LEN		1
#define HDCP_2_2_DP_RXSTATUS_READY(x)		((x) & BIT(0))
#define HDCP_2_2_DP_RXSTATUS_H_PRIME(x)		((x) & BIT(1))
#define HDCP_2_2_DP_RXSTATUS_PAIRING(x)		((x) & BIT(2))
#define HDCP_2_2_DP_RXSTATUS_REAUTH_REQ(x)	((x) & BIT(3))
#define HDCP_2_2_DP_RXSTATUS_LINK_FAILED(x)	((x) & BIT(4))

/* DP 1.2 Sideband message defines */
/* peer device type - DP 1.2a Table 2-92 */
#define DP_PEER_DEVICE_NONE		0x0
#define DP_PEER_DEVICE_SOURCE_OR_SST	0x1
#define DP_PEER_DEVICE_MST_BRANCHING	0x2
#define DP_PEER_DEVICE_SST_SINK		0x3
#define DP_PEER_DEVICE_DP_LEGACY_CONV	0x4

/* DP 1.2 MST sideband request names DP 1.2a Table 2-80 */
#define DP_GET_MSG_TRANSACTION_VERSION	0x00 /* DP 1.3 */
#define DP_LINK_ADDRESS			0x01
#define DP_CONNECTION_STATUS_NOTIFY	0x02
#define DP_ENUM_PATH_RESOURCES		0x10
#define DP_ALLOCATE_PAYLOAD		0x11
#define DP_QUERY_PAYLOAD		0x12
#define DP_RESOURCE_STATUS_NOTIFY	0x13
#define DP_CLEAR_PAYLOAD_ID_TABLE	0x14
#define DP_REMOTE_DPCD_READ		0x20
#define DP_REMOTE_DPCD_WRITE		0x21
#define DP_REMOTE_I2C_READ		0x22
#define DP_REMOTE_I2C_WRITE		0x23
#define DP_POWER_UP_PHY			0x24
#define DP_POWER_DOWN_PHY		0x25
#define DP_SINK_EVENT_NOTIFY		0x30
#define DP_QUERY_STREAM_ENC_STATUS	0x38

/* DP 1.2 MST sideband reply types */
#define DP_SIDEBAND_REPLY_ACK		0x00
#define DP_SIDEBAND_REPLY_NAK		0x01

/* DP 1.2 MST sideband nak reasons - table 2.84 */
#define DP_NAK_WRITE_FAILURE		0x01
#define DP_NAK_INVALID_READ		0x02
#define DP_NAK_CRC_FAILURE		0x03
#define DP_NAK_BAD_PARAM		0x04
#define DP_NAK_DEFER			0x05
#define DP_NAK_LINK_FAILURE		0x06
#define DP_NAK_NO_RESOURCES		0x07
#define DP_NAK_DPCD_FAIL		0x08
#define DP_NAK_I2C_NAK			0x09
#define DP_NAK_ALLOCATE_FAIL		0x0a

#define MODE_I2C_START	1
#define MODE_I2C_WRITE	2
#define MODE_I2C_READ	4
#define MODE_I2C_STOP	8

/* DP 1.2 MST PORTs - Section 2.5.1 v1.2a spec */
#define DP_MST_PHYSICAL_PORT_0 0
#define DP_MST_LOGICAL_PORT_0 8

#define DP_LINK_STATUS_SIZE	   6

#define DP_BRANCH_OUI_HEADER_SIZE	0xc
#define DP_RECEIVER_CAP_SIZE		0xf
#define DP_DSC_RECEIVER_CAP_SIZE        0xf
#define EDP_PSR_RECEIVER_CAP_SIZE	2
#define EDP_DISPLAY_CTL_CAP_SIZE	3



#define DP_SDP_AUDIO_TIMESTAMP		0x01
#define DP_SDP_AUDIO_STREAM		0x02
#define DP_SDP_EXTENSION		0x04 /* DP 1.1 */
#define DP_SDP_AUDIO_COPYMANAGEMENT	0x05 /* DP 1.2 */
#define DP_SDP_ISRC			0x06 /* DP 1.2 */
#define DP_SDP_VSC			0x07 /* DP 1.2 */
#define DP_SDP_CAMERA_GENERIC(i)	(0x08 + (i)) /* 0-7, DP 1.3 */
#define DP_SDP_PPS			0x10 /* DP 1.4 */
#define DP_SDP_VSC_EXT_VESA		0x20 /* DP 1.4 */
#define DP_SDP_VSC_EXT_CEA		0x21 /* DP 1.4 */
/* 0x80+ CEA-861 infoframe types */

/**
 * struct dp_sdp_header - DP secondary data packet header
 * @HB0: Secondary Data Packet ID
 * @HB1: Secondary Data Packet Type
 * @HB2: Secondary Data Packet Specific header, Byte 0
 * @HB3: Secondary Data packet Specific header, Byte 1
 */

#define EDP_SDP_HEADER_REVISION_MASK		0x1F
#define EDP_SDP_HEADER_VALID_PAYLOAD_BYTES	0x1F
#define DP_SDP_PPS_HEADER_PAYLOAD_BYTES_MINUS_1 0x7F



#define EDP_VSC_PSR_STATE_ACTIVE	(1<<0)
#define EDP_VSC_PSR_UPDATE_RFB		(1<<1)
#define EDP_VSC_PSR_CRC_VALUES_VALID	(1<<2)

/**
 * enum dp_pixelformat - drm DP Pixel encoding formats
 *
 * This enum is used to indicate DP VSC SDP Pixel encoding formats.
 * It is based on DP 1.4 spec [Table 2-117: VSC SDP Payload for DB16 through
 * DB18]
 *
 * @DP_PIXELFORMAT_RGB: RGB pixel encoding format
 * @DP_PIXELFORMAT_YUV444: YCbCr 4:4:4 pixel encoding format
 * @DP_PIXELFORMAT_YUV422: YCbCr 4:2:2 pixel encoding format
 * @DP_PIXELFORMAT_YUV420: YCbCr 4:2:0 pixel encoding format
 * @DP_PIXELFORMAT_Y_ONLY: Y Only pixel encoding format
 * @DP_PIXELFORMAT_RAW: RAW pixel encoding format
 * @DP_PIXELFORMAT_RESERVED: Reserved pixel encoding format
 */
enum dp_pixelformat {
	DP_PIXELFORMAT_RGB = 0,
	DP_PIXELFORMAT_YUV444 = 0x1,
	DP_PIXELFORMAT_YUV422 = 0x2,
	DP_PIXELFORMAT_YUV420 = 0x3,
	DP_PIXELFORMAT_Y_ONLY = 0x4,
	DP_PIXELFORMAT_RAW = 0x5,
	DP_PIXELFORMAT_RESERVED = 0x6,
};

/**
 * enum dp_colorimetry - drm DP Colorimetry formats
 *
 * This enum is used to indicate DP VSC SDP Colorimetry formats.
 * It is based on DP 1.4 spec [Table 2-117: VSC SDP Payload for DB16 through
 * DB18] and a name of enum member follows DRM_MODE_COLORIMETRY definition.
 *
 * @DP_COLORIMETRY_DEFAULT: sRGB (IEC 61966-2-1) or
 *                          ITU-R BT.601 colorimetry format
 * @DP_COLORIMETRY_RGB_WIDE_FIXED: RGB wide gamut fixed point colorimetry format
 * @DP_COLORIMETRY_BT709_YCC: ITU-R BT.709 colorimetry format
 * @DP_COLORIMETRY_RGB_WIDE_FLOAT: RGB wide gamut floating point
 *                                 (scRGB (IEC 61966-2-2)) colorimetry format
 * @DP_COLORIMETRY_XVYCC_601: xvYCC601 colorimetry format
 * @DP_COLORIMETRY_OPRGB: OpRGB colorimetry format
 * @DP_COLORIMETRY_XVYCC_709: xvYCC709 colorimetry format
 * @DP_COLORIMETRY_DCI_P3_RGB: DCI-P3 (SMPTE RP 431-2) colorimetry format
 * @DP_COLORIMETRY_SYCC_601: sYCC601 colorimetry format
 * @DP_COLORIMETRY_RGB_CUSTOM: RGB Custom Color Profile colorimetry format
 * @DP_COLORIMETRY_OPYCC_601: opYCC601 colorimetry format
 * @DP_COLORIMETRY_BT2020_RGB: ITU-R BT.2020 R' G' B' colorimetry format
 * @DP_COLORIMETRY_BT2020_CYCC: ITU-R BT.2020 Y'c C'bc C'rc colorimetry format
 * @DP_COLORIMETRY_BT2020_YCC: ITU-R BT.2020 Y' C'b C'r colorimetry format
 */
enum dp_colorimetry {
	DP_COLORIMETRY_DEFAULT = 0,
	DP_COLORIMETRY_RGB_WIDE_FIXED = 0x1,
	DP_COLORIMETRY_BT709_YCC = 0x1,
	DP_COLORIMETRY_RGB_WIDE_FLOAT = 0x2,
	DP_COLORIMETRY_XVYCC_601 = 0x2,
	DP_COLORIMETRY_OPRGB = 0x3,
	DP_COLORIMETRY_XVYCC_709 = 0x3,
	DP_COLORIMETRY_DCI_P3_RGB = 0x4,
	DP_COLORIMETRY_SYCC_601 = 0x4,
	DP_COLORIMETRY_RGB_CUSTOM = 0x5,
	DP_COLORIMETRY_OPYCC_601 = 0x5,
	DP_COLORIMETRY_BT2020_RGB = 0x6,
	DP_COLORIMETRY_BT2020_CYCC = 0x6,
	DP_COLORIMETRY_BT2020_YCC = 0x7,
};

/**
 * enum dp_dynamic_range - drm DP Dynamic Range
 *
 * This enum is used to indicate DP VSC SDP Dynamic Range.
 * It is based on DP 1.4 spec [Table 2-117: VSC SDP Payload for DB16 through
 * DB18]
 *
 * @DP_DYNAMIC_RANGE_VESA: VESA range
 * @DP_DYNAMIC_RANGE_CTA: CTA range
 */
enum dp_dynamic_range {
	DP_DYNAMIC_RANGE_VESA = 0,
	DP_DYNAMIC_RANGE_CTA = 1,
};

/**
 * enum dp_content_type - drm DP Content Type
 *
 * This enum is used to indicate DP VSC SDP Content Types.
 * It is based on DP 1.4 spec [Table 2-117: VSC SDP Payload for DB16 through
 * DB18]
 * CTA-861-G defines content types and expected processing by a sink device
 *
 * @DP_CONTENT_TYPE_NOT_DEFINED: Not defined type
 * @DP_CONTENT_TYPE_GRAPHICS: Graphics type
 * @DP_CONTENT_TYPE_PHOTO: Photo type
 * @DP_CONTENT_TYPE_VIDEO: Video type
 * @DP_CONTENT_TYPE_GAME: Game type
 */
enum dp_content_type {
	DP_CONTENT_TYPE_NOT_DEFINED = 0x00,
	DP_CONTENT_TYPE_GRAPHICS = 0x01,
	DP_CONTENT_TYPE_PHOTO = 0x02,
	DP_CONTENT_TYPE_VIDEO = 0x03,
	DP_CONTENT_TYPE_GAME = 0x04,
};

/**
 * struct drm_dp_vsc_sdp - drm DP VSC SDP
 *
 * This structure represents a DP VSC SDP of drm
 * It is based on DP 1.4 spec [Table 2-116: VSC SDP Header Bytes] and
 * [Table 2-117: VSC SDP Payload for DB16 through DB18]
 *
 * @sdp_type: secondary-data packet type
 * @revision: revision number
 * @length: number of valid data bytes
 * @pixelformat: pixel encoding format
 * @colorimetry: colorimetry format
 * @bpc: bit per color
 * @dynamic_range: dynamic range information
 * @content_type: CTA-861-G defines content types and expected processing by a sink device
 */
struct drm_dp_vsc_sdp {
	unsigned char sdp_type;
	unsigned char revision;
	unsigned char length;
	enum dp_pixelformat pixelformat;
	enum dp_colorimetry colorimetry;
	int bpc;
	enum dp_dynamic_range dynamic_range;
	enum dp_content_type content_type;
};

EFI_STATUS SetupClockeDP(i915_CONTROLLER* controller);
EFI_STATUS SetupClockDP(i915_CONTROLLER* controller);
EFI_STATUS SetupDDIBufferDP(i915_CONTROLLER* controller);
EFI_STATUS SetupTranscoderAndPipeEDP(i915_CONTROLLER* controller);
EFI_STATUS SetupTranscoderAndPipeDP(i915_CONTROLLER* controller);
void intel_dp_pps_init(i915_CONTROLLER* controller);