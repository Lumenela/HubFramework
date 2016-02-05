#import <Foundation/Foundation.h>

@protocol HUBFeatureRegistry;
@protocol HUBComponentRegistry;
@protocol HUBJSONSchemaRegistry;
@protocol HUBComponentFallbackHandler;
@protocol HUBConnectivityStateResolver;

NS_ASSUME_NONNULL_BEGIN

/**
 *  This class is the main entry point into the Hub Framework
 *
 *  An application using the Hub Framework should create an instance of this class,
 *  and retain it in a central location (such as its App Delegate)
 */
@interface HUBManager : NSObject

/// The feature registry used by this Hub Manager. See the documentation for `HUBFeatureRegistry` for more info.
@property (nonatomic, strong, readonly) id<HUBFeatureRegistry> featureRegistry;

/// The component registry used by this Hub Manager. See the documentation for `HUBComponentRegistry` for more info.
@property (nonatomic, strong, readonly) id<HUBComponentRegistry> componentRegistry;

/// The JSON schema registry used by this Hub Manager. See the documentation for `HUBJSONSchemaRegistry` for more info.
@property (nonatomic, strong, readonly) id<HUBJSONSchemaRegistry> JSONSchemaRegistry;

/**
 *  Initialize an instance of this class with a component fallback handler
 *
 *  @param componentFallbackHandler An object responsible for handling the case of an unrecognized component
 *         identifier. This object will be retained.
 *  @param connectivityStateResolver An object responsible for determining the current connectivity state of
 *         the application. This object will be retained.
 */
- (instancetype)initWithComponentFallbackHandler:(id<HUBComponentFallbackHandler>)componentFallbackHandler
                       connectivityStateResolver:(id<HUBConnectivityStateResolver>)connectivityStateResolver NS_DESIGNATED_INITIALIZER;

#pragma mark - Unavailable initializers

/// This class needs to be initialized with its designated initializer
- (instancetype)init NS_UNAVAILABLE;

/// This class needs to be initialized with its designated initializer
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
