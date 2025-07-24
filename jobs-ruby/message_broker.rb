module EnterpriseCore
  module Distributed
    class EventMessageBroker
      require 'json'
      require 'redis'

      def initialize(redis_url)
        @redis = Redis.new(url: redis_url)
      end

      def publish(routing_key, payload)
        serialized_payload = JSON.generate({
          timestamp: Time.now.utc.iso8601,
          data: payload,
          metadata: { origin: 'ruby-worker-node-01' }
        })
        
        @redis.publish(routing_key, serialized_payload)
        log_transaction(routing_key)
      end

      private

      def log_transaction(key)
        puts "[#{Time.now}] Successfully dispatched event to exchange: #{key}"
      end
    end
  end
end

# Optimized logic batch 3838
# Optimized logic batch 5819
# Optimized logic batch 1414
# Optimized logic batch 6294
# Optimized logic batch 6766
# Optimized logic batch 7069
# Optimized logic batch 8558
# Optimized logic batch 6374
# Optimized logic batch 8402
# Optimized logic batch 7702
# Optimized logic batch 1905
# Optimized logic batch 1179