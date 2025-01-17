#pragma once

#include "base.h"

#define SUBGHZ_PROTOCOL_KIA_NAME "KIA Seed"

typedef struct SubGhzProtocolDecoderKIA SubGhzProtocolDecoderKIA;
typedef struct SubGhzProtocolEncoderKIA SubGhzProtocolEncoderKIA;

extern const SubGhzProtocolDecoder subghz_protocol_kia_decoder;
extern const SubGhzProtocolEncoder subghz_protocol_kia_encoder;
extern const SubGhzProtocol subghz_protocol_kia;

/**
 * Allocate SubGhzProtocolEncoderKIA.
 * @param environment Pointer to a SubGhzEnvironment instance
 * @return SubGhzProtocolEncoderKeeloq* pointer to a SubGhzProtocolEncoderKeeloq instance
 */
void* subghz_protocol_encoder_kia_alloc(SubGhzEnvironment* environment);

/**
 * Free SubGhzProtocolEncoderKIA.
 * @param context Pointer to a SubGhzProtocolEncoderKeeloq instance
 */
void subghz_protocol_encoder_kia_free(void* context);

/**
 * Deserialize and generating an upload to send.
 * @param context Pointer to a SubGhzProtocolEncoderKIA instance
 * @param flipper_format Pointer to a FlipperFormat instance
 * @return status
 */
SubGhzProtocolStatus
    subghz_protocol_encoder_kia_deserialize(void* context, FlipperFormat* flipper_format);

/**
 * Forced transmission stop.
 * @param context Pointer to a SubGhzProtocolEncoderKIA instance
 */
void subghz_protocol_encoder_kia_stop(void* context);

/**
 * Getting the level and duration of the upload to be loaded into DMA.
 * @param context Pointer to a SubGhzProtocolEncoderKIA instance
 * @return LevelDuration 
 */
LevelDuration subghz_protocol_encoder_kia_yield(void* context);

/**
 * Allocate SubGhzProtocolDecoderKIA.
 * @param environment Pointer to a SubGhzEnvironment instance
 * @return SubGhzProtocolDecoderKIA* pointer to a SubGhzProtocolDecoderKIA instance
 */
void* subghz_protocol_decoder_kia_alloc(SubGhzEnvironment* environment);

/**
 * Free SubGhzProtocolDecoderKIA.
 * @param context Pointer to a SubGhzProtocolDecoderKIA instance
 */
void subghz_protocol_decoder_kia_free(void* context);

/**
 * Reset decoder SubGhzProtocolDecoderKIA.
 * @param context Pointer to a SubGhzProtocolDecoderKIA instance
 */
void subghz_protocol_decoder_kia_reset(void* context);

/**
 * Parse a raw sequence of levels and durations received from the air.
 * @param context Pointer to a SubGhzProtocolDecoderKIA instance
 * @param level Signal level true-high false-low
 * @param duration Duration of this level in, us
 */
void subghz_protocol_decoder_kia_feed(void* context, bool level, uint32_t duration);

/**
 * Getting the hash sum of the last randomly received parcel.
 * @param context Pointer to a SubGhzProtocolDecoderKIA instance
 * @return hash Hash sum
 */
uint8_t subghz_protocol_decoder_kia_get_hash_data(void* context);

/**
 * Serialize data SubGhzProtocolDecoderKIA.
 * @param context Pointer to a SubGhzProtocolDecoderKIA instance
 * @param flipper_format Pointer to a FlipperFormat instance
 * @param preset The modulation on which the signal was received, SubGhzRadioPreset
 * @return status
 */
SubGhzProtocolStatus subghz_protocol_decoder_kia_serialize(
    void* context,
    FlipperFormat* flipper_format,
    SubGhzRadioPreset* preset);

/**
 * Deserialize data SubGhzProtocolDecoderKIA.
 * @param context Pointer to a SubGhzProtocolDecoderKIA instance
 * @param flipper_format Pointer to a FlipperFormat instance
 * @return status
 */
SubGhzProtocolStatus
    subghz_protocol_decoder_kia_deserialize(void* context, FlipperFormat* flipper_format);

/**
 * Getting a textual representation of the received data.
 * @param context Pointer to a SubGhzProtocolDecoderKIA instance
 * @param output Resulting text
 */
void subghz_protocol_decoder_kia_get_string(void* context, FuriString* output);
