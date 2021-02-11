#ifndef _PSP2_KERNEL_UTILS_H_
#define _PSP2_KERNEL_UTILS_H_

#include <stdint.h>
#include <scetypes.h>

#ifdef __cplusplus
extern "C" {
#endif

#define SCE_SHA1_BLOCK_SIZE    64
#define SCE_SHA1_DIGEST_SIZE   20
#define SCE_SHA224_BLOCK_SIZE  64
#define SCE_SHA224_DIGEST_SIZE 28
#define SCE_SHA256_BLOCK_SIZE  64
#define SCE_SHA256_DIGEST_SIZE 32

typedef struct SceSha1Context {
	uint32_t h[5];
	uint16_t usRemains;
	uint16_t usComputed;
	uint64_t ullTotalLen;
	char buf[SCE_SHA1_BLOCK_SIZE];
	char result[SCE_SHA1_DIGEST_SIZE];
	uint32_t pad;
} SceSha1Context;

typedef struct SceSha224Context {
	uint32_t h[8];
	uint32_t pad;
	uint16_t usRemains;
	uint16_t usComputed;
	uint64_t ullTotalLen;
	char buf[SCE_SHA224_BLOCK_SIZE];
	char result[SCE_SHA224_DIGEST_SIZE];
	uint32_t pad2;
} SceSha224Context;

typedef struct SceSha256Context {
	uint32_t h[8];
	uint32_t pad;
	uint16_t usRemains;
	uint16_t usComputed;
	uint64_t ullTotalLen;
	char buf[SCE_SHA256_BLOCK_SIZE];
	char result[SCE_SHA256_DIGEST_SIZE];
} SceSha256Context;

struct SceDeflatePartialInputParam;

typedef struct SceDeflatePartialInputParam {
	uint32_t size;
	const void *pBufEnd;
	void *cookie;
	const void *(* SceDeflateDecompressPartialInputCallback)(struct SceDeflatePartialInputParam* param, uint32_t outputsize);
} SceDeflatePartialInputParam;

typedef struct {
	uint8_t data[976];
} SceAesContext;

int sceSha1BlockInit(SceSha1Context *ctx);
int sceSha1BlockUpdate(SceSha1Context *ctx, const void *plain, SceSize len);
int sceSha1BlockResult(SceSha1Context *ctx, void *result);
int sceSha1Digest(const void *plain, SceSize len, void *digest);

int sceSha224BlockInit(SceSha224Context *ctx);
int sceSha224BlockUpdate(SceSha224Context *ctx, const void *plain, SceSize len);
int sceSha224BlockResult(SceSha224Context *ctx, void *result);
int sceSha224Digest(const void *plain, SceSize len, void *digest);

int sceSha256BlockInit(SceSha256Context *ctx);
int sceSha256BlockUpdate(SceSha256Context *ctx, const void *plain, SceSize len);
int sceSha256BlockResult(SceSha256Context *ctx, void *result);
int sceSha256Digest(const void *plain, SceSize len, void *digest);

int sceHmacSha1Digest(const void *key, SceSize key_len, const void *plain, SceSize len, void *digest);
int sceHmacSha224Digest(const void *key, SceSize key_len, const void *plain, SceSize len, void *digest);
int sceHmacSha256Digest(const void *key, SceSize key_len, const void *plain, SceSize len, void *digest);

/**
 * @param[out] dst - dst buf
 * @param[in] dst_size - dst buf size
 * @param[in] src - Gzip compressed data
 * @param[out] crc32 - crc32 when decompressed
 *
 * @return decompressed size on success, < 0 on error.
 */
int sceGzipDecompress(void *dst, SceSize dst_size, const void *src, uint32_t *crc32);

/**
 * @brief Check magic of Gzip header
 *
 * @param[in] src - Gzip compressed data
 *
 * @return 1 on success,  0 is not Gzip data.
 */
int sceGzipIsValid(const void *src);

/**
 * @brief Get filename etc. in Gzip data
 *
 * @param[in] src - Gzip compressed data
 * @param[out] extra - Get information on extra-field
 * @param[out] name - Get filename information
 * @param[out] comment - Get comment information
 * @param[out] crc - Get CRC16 information
 * @param[out] data - Get compressed data start address
 *
 * @return 0 on success, < 0 on error.
 */
int sceGzipGetInfo(const void *src, const void **extra, const char **name, const char **comment, unsigned short *crc, const void **data);

/**
 * @brief Get filename string address
 *
 * @param[in] src - Gzip compressed data
 *
 * @return string address on success, NULL on error.
 */
const char *sceGzipGetName(const void *src);

/**
 * @brief Get comment string address
 *
 * @param[in] src - Gzip compressed data
 *
 * @return string address on success, NULL on error.
 */
const char *sceGzipGetComment(const void *src);

/**
 * @brief Get compressed data start address
 *
 * @param[in] src - Gzip compressed data
 *
 * @return compressed data address on success, NULL on error.
 */
const void *sceGzipGetCompressedData(const void *src);

/**
 * @brief Get filename etc. in Zlib data
 *
 * @param[in] src - Zlib compressed data
 * @param[out] cmf - Get CMF (Compression Method and flags)
 * @param[out] flg - Get FLG (FLaGs)
 * @param[out] dictid - Get DictId
 * @param[out] data - Get compressed data start address
 *
 * @return 0 on success, < 0 on error.
 */
int sceZlibGetInfo(const void *src, unsigned char *cmf, unsigned char *flg, unsigned int *dictid, const void **data);

/**
 * @brief Get compressed data start address
 *
 * @param[in] src - Gzip compressed data
 *
 * @return compressed data address on success, NULL on error.
 */
const void *sceZlibGetCompressedData(const void *src);

/**
 * @param[out] dst - dst buf
 * @param[in] dst_size - dst buf size
 * @param[in] src - Zlib compressed data
 * @param[out] adler32 - adler32 when decompressed
 *
 * @return decompressed size on success, < 0 on error.
 */
int sceZlibDecompress(void *dst, SceSize dst_size, const void *src, uint32_t *adler32);

/**
 * @param[out] dst - dst buf
 * @param[in] dst_size - dst buf size
 * @param[in] src - Deflate compressed data
 * @param[out] next - next data
 *
 * @return decompressed size on success, < 0 on error.
 */
int sceDeflateDecompress(void *dst, SceSize dst_size, const void *src, const void **next);
int sceDeflateDecompressPartial(void *dst, SceSize dst_size, const void *src, const void **next, SceDeflatePartialInputParam *cbInfo);

/**
 * @param[out] ctx - out key data, etc...
 * @param[in] blocksize - 128 or 192 or 256
 * @param[in] keysize - 128 or 192 or 256
 * @param[in] key - key data
 *
 * @return 0 on success, < 0 on error.
 */
int sceAesInit1(SceAesContext *ctx, SceSize blocksize, SceSize keysize, const void *key);
int sceAesInit2(SceAesContext *ctx, SceSize blocksize, SceSize keysize, const void *key);
int sceAesInit3(SceAesContext *ctx, SceSize blocksize, SceSize keysize, const void *key);

int sceAesDecrypt1(SceAesContext *ctx, const void *src, void *dst);
int sceAesDecrypt2(SceAesContext *ctx, const void *src, void *dst);

int sceAesEncrypt1(SceAesContext *ctx, const void *src, void *dst);
int sceAesEncrypt2(SceAesContext *ctx, const void *src, void *dst);

#ifdef __cplusplus
}
#endif

#endif /* _PSP2_KERNEL_UTILS_H_ */
