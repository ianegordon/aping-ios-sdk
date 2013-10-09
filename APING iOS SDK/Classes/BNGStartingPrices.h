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

/**
 * Includes all starting prices for a `BNGRunner`.
 */
@interface BNGStartingPrices : NSObject

/**
 * What the starting price would be if the market was reconciled now taking into account
 * the SP bets as well as unmatched exchange bets on the same selection in the exchange.
 */
@property (nonatomic, strong) NSDecimalNumber *nearPrice;

/**
 * What the starting price would be if the market was reconciled now taking into account
 * only the currently place SP bets. The Far Price is not as complicated but not as
 * accurate and only accounts for money on the exchange at SP.
 */
@property (nonatomic, strong) NSDecimalNumber *farPrice;
@property (nonatomic, copy) NSArray *backStakeTaken;
@property (nonatomic, copy) NSArray *layLiabilityTaken;

/**
 * The final BSP price for this runner. Only available for a BSP market that has been reconciled.
 */
@property (nonatomic, strong) NSDecimalNumber *actualSP;

@end