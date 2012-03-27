//
//  THWebUtility.h
//  UserSystem
//
//  Created by Hao Tan on 12-3-20.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>

enum
{
    THHashKindMd5,
    THHashKindSha1,
    THHashKindSha256,
    THHashKindSha512,
};
typedef NSInteger THHashKind;

enum
{
    THCryptorKindAES128,
    THCryptorKindDES,
};
typedef NSInteger THCryptorKind;

enum {
    THOperationKindEncrypt, 
    THOperationKindDecrypt,     
};
typedef NSInteger THOperationKind;

@interface THWebUtility : NSObject

//Hash 算法
+ (NSString *)hashFile:(NSString *)filePath with:(THHashKind)hashKind;
+ (NSString *)hashData:(NSData *)data with:(THHashKind)hashKind;
+ (NSString *)hashString:(NSString *)string with:(THHashKind)hashKind;

//HMAC 算法 (keyed-Hash Message Authentication Code,密钥相关的哈希运算消息认证码)
+ (NSString *)hMacData:(NSData *)data withSecretKey:(NSString *)secretKey withHashKind:(THHashKind)hashKind;
+ (NSString *)hMacString:(NSString *)string withSecretKey:(NSString *)secretKey withHashKind:(THHashKind)hashKind;

//加密算法
+ (NSData *)cryptorData:(NSData *)data key:(NSData *)key iv:(NSData *)iv operation:(THOperationKind)operation kind:(THCryptorKind)cryKind;

@end
