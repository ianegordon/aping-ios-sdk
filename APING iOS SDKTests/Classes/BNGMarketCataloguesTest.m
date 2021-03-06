// Copyright (c) 2013 The Sporting Exchange Limited
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
// 1. Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
// 2. Redistributions in binary form must reproduce the above copyright
// notice, this list of conditions and the following disclaimer in the
// documentation and/or other materials provided with the distribution.
// 3. All advertising materials mentioning features or use of this software
// must display the following acknowledgement:
// This product includes software developed by The Sporting Exchange Limited.
// 4. Neither the name of The Sporting Exchange Limited nor the
// names of its contributors may be used to endorse or promote products
// derived from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE SPORTING EXCHANGE LIMITED ''AS IS'' AND ANY
// EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL THE SPORTING EXCHANGE LIMITED BE LIABLE FOR ANY
// DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
// (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
// LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
// ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#import "BNGMarketCataloguesTest.h"

#import "APING.h"
#import "BNGMarketCatalogue.h"
#import "BNGMarketCatalogueFilter.h"
#import "BNGURLProtocolResourceLoader.h"
#import "BNGTimeRange.h"
#import "BNGTestUtilities.h"

@implementation BNGMarketCataloguesTest

- (void)testMarketCataloguesApiCall
{
    [NSURLProtocol registerClass:[BNGURLProtocolResourceLoader class]];
    
    [[APING sharedInstance] registerApplicationKey:BNGTestUtilitiesApplicationKey ssoKey:BNGTestUtilitiesSSOKey];
    
    dispatch_semaphore_t semaphore = dispatch_semaphore_create(0);
    
    BNGMarketCatalogueFilter *marketFilter = [[BNGMarketCatalogueFilter alloc] init];
    marketFilter.marketIds = @[@"1.110566563"];
    marketFilter.marketStartTime = [[BNGTimeRange alloc] initWithDatesFrom:[NSDate date] to:[NSDate date]];
    [BNGMarketCatalogue listMarketCataloguesWithFilter:marketFilter completionBlock:^(NSArray *results, NSError *connectionError, BNGAPIError *apiError) {
       
        BNGMarketCatalogue *marketCatalogue = results[0];
        STAssertTrue(results.count == 1, @"There should be only one BNGMarketCatalogue");
        STAssertTrue(marketCatalogue.runners.count == 20, @"There should be 20 runners associated with the market catalogue");
        
        dispatch_semaphore_signal(semaphore);
        
    }];
    
    while (dispatch_semaphore_wait(semaphore, DISPATCH_TIME_NOW))
        [[NSRunLoop currentRunLoop] runMode:NSDefaultRunLoopMode
                                 beforeDate:[NSDate dateWithTimeIntervalSinceNow:10]];
    dispatch_release(semaphore);
}

@end
