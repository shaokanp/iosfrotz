#import <Foundation/Foundation.h>


@protocol HTTPResponse

- (UInt64)contentLength;

- (UInt64)offset;
- (void)setOffset:(UInt64)offset;

- (NSData *)readDataOfLength:(unsigned int)length;

#if MAC_OS_X_VERSION_MAX_ALLOWED >= MAC_OS_X_VERSION_10_5

@optional
- (NSDictionary *)httpHeaders;

#endif

@end

@interface HTTPFileResponse : NSObject <HTTPResponse>
{
	NSString *filePath;
	NSFileHandle *fileHandle;
	NSString *fileName;
}

@property(retain) NSString* fileName;
- (instancetype)initWithFilePath:(NSString *)filePath NS_DESIGNATED_INITIALIZER;
@property (nonatomic, readonly, copy) NSString *filePath;

@end

@interface HTTPDataResponse : NSObject <HTTPResponse>
{
	unsigned offset;
	NSData *data;
}

- (instancetype)initWithData:(NSData *)data NS_DESIGNATED_INITIALIZER;

@end