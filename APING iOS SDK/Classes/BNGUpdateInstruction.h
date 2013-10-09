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
// This product includes software developed by the <organization>.
// 4. Neither the name of the <organization> nor the
// names of its contributors may be used to endorse or promote products
// derived from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY <COPYRIGHT HOLDER> ''AS IS'' AND ANY
// EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL <COPYRIGHT HOLDER> BE LIABLE FOR ANY
// DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
// (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
// LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
// ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#import "BNGDictionaryRepresentation.h"
#import "BNGOrder.h"

/**
 * `BNGUpdateInstruction`s are used in a `updateOrders` API call.
 */
@interface BNGUpdateInstruction : NSObject <BNGDictionaryRepresentation>

/**
 * Unique identifier for the bet that the client wishes to update.
 */
@property (nonatomic, copy) NSString *betId;

/**
 * The new price at which the client wishes to update the bet.
 */
@property (nonatomic) BNGPersistanceType persistenceType;

/**
 * Simple initialiser.
 * @param betId uniquely identifies the bet associated with this update instruction.
 * @param newPersistanceType defines the new BNGPersistanceType for the bet
 * @return a `BNGUpdateInstruction` object.
 */
- (instancetype)initWithBetId:(NSString *)betId newPersistanceType:(BNGPersistanceType)newPersistanceType;

/**
 * Given a collection of `BNGUpdateInstruction`s, this method returns a fully-formed
 * NSDictionary representation of these instructions.
 * @param updateInstructions collection of `BNGUpdateInstruction`s
 * @return a collection of NSDictionary representations corresponding to the updateInstructions parameter.
 */
+ (NSArray *)dictionaryRepresentationsForBNGUpdateInstructions:(NSArray *)updateInstructions;

@end