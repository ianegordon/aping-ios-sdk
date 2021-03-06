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

#import "BNGDictionaryRepresentation.h"

/**
 * Used when cancelling bets. Contains information the server requires to uniquely identifiy
 * a bet that the client wishes to cancel. Only unmatched bets are cancellable.
 */
@interface BNGCancelInstruction : NSObject <BNGDictionaryRepresentation>

/**
 * Unique identifier for the bet that the client wants to cancel. This is a required
 * parameter to the `cancelOrder` API call.
 */
@property (nonatomic, copy) NSString *betId;

/**
 * Dictates how much of the bet to cancel. If this parameter is excluded from the
 * `BNGCancelInstruction`, it is assumed that the client wants to cancel ALL of the bet.
 */
@property (nonatomic, strong) NSDecimalNumber *sizeReduction;

/**
 * Simple initialiser.
 * @param betId uniquely identifies the bet associated with this cancel instruction.
 * @param sizeReduction defines how much of the bet that the client wishes to cancel.
 * @return a `BNGCancelInstruction` object.
 */
- (instancetype)initWithBetId:(NSString *)betId sizeReduction:(NSDecimalNumber *)sizeReduction;

/**
 * Given a collection of `BNGCancelInstruction`s, this method returns a fully-formed
 * NSDictionary representation of these instructions.
 * @param cancelInstructions collection of `BNGCancelInstruction`s
 * @return a collection of NSDictionary representations corresponding to the cancelInstructions parameter.
 */
+ (NSArray *)dictionaryRepresentationsForBNGCancelInstructions:(NSArray *)cancelInstructions;

@end
